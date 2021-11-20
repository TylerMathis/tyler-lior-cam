#!/usr/bin/env python3

# Usage:
# ./catchtest.py command_to_run_your_program < testcase_file
# ./catchtest.py command_to_run_your_program
# Examples:
# ./catchtest.py java MyClass
# ./catchtest.py ./a.out < my_testcase
# ./catchtest.py ./submission.py
# ./catchtest.py python3 submission.py < my_testcase


import sys
import subprocess
import random


def allowed(v):
    return all(1 <= c <= n for c in v)


def distance(v1, v2):
    return sum(map(lambda d: abs(d[0] - d[1]), zip(v1, v2)))


random.seed(42)

if len(sys.argv) == 1:
    print("Usage:")
    print("1) ./catchtest.py command_to_run_your_program < testcase_file")
    print("2) ./catchtest.py command_to_run_your_program")
    print("   and enter test data manually")
    print("(command_to_run_your_program may include spaces, like: ./catchtest.py java MyClass)")
    sys.exit(1)

# get initial input from testcase file or manually from sys.stdin
print("Reading input...")
try:
    n = int(input().strip())
    x1, y1, x2, y2 = map(int, input().strip().split(" "))
    ax, ay = map(int, input().strip().split(" "))
except ValueError as e:
    print("Invalid testcase! Please read the problem statement carefully.")
    sys.exit(1)

# check input
if not 3 <= n <= 100 \
        or not all(allowed(v) for v in [(x1, y1), (x2, y2), (ax, ay)]) \
        or (ax, ay) in {(x1, y1), (x2, y2)}:
    print("Invalid testcase! Please read the problem statement carefully.")
    sys.exit(1)

# open submission
try:
    submission = subprocess.Popen(args=sys.argv[1:], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
except OSError as e:
    print(f"Failed to start your program: {e}")
    sys.exit(1)

# send initial input to submission
submission.stdin.write(f"{n:d}\n".encode())
submission.stdin.write(f"{x1:d} {y1:d} {x2:d} {y2:d}\n".encode())

print("Running the game:")
print(f"AI is at ({ax:d},{ay:d})")
# game loop
turn = 1
caught = False
while turn < 600:
    submission.stdin.write(f"{ax:d} {ay:d}\n".encode())
    submission.stdin.flush()

    # process team's move
    line = submission.stdout.readline().decode()
    data = line.split(" ")
    if len(data) != 4:
        print("Your program responded with " + f"an invalid reply: {line}" if line.strip() else "an empty reply")
        sys.exit(0)
    try:
        x1n, y1n, x2n, y2n = map(int, data)
    except ValueError:
        print(f"Your program responded with an invalid reply: {line}")
        sys.exit(0)

    # validate move
    if not allowed((x1n, y1n)) or not allowed((x2n, y2n)) \
            or distance((x1, y1), (x1n, y1n)) > 1 or distance((x2, y2), (x2n, y2n)) > 1:
        print(f"Your program attempted an invalid move: ({x1n:d},{y1n:d}) ({x2n:d},{y2n:d})")
        sys.exit(0)
    x1, y1, x2, y2 = x1n, y1n, x2n, y2n

    print(f"You: ({x1:d},{y1:d}) ({x2:d},{y2:d})")

    # check if team caught the ai
    if (ax, ay) in {(x1, y1), (x2, y2)}:
        print("You caught the AI!")
        caught = True
        submission.stdin.write("0 0\n".encode())
        submission.stdin.flush()
        break

    # make ai's move
    valid_moves = [(ax, ay)]
    for (a, b) in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
        move = (ax + a, ay + b)
        if allowed(move) and move not in {(x1, y1), (x2, y2)}:
            valid_moves.append(move)
    axn, ayn = random.choice(valid_moves)
    print(f"AI:  ({axn:d},{ayn:d})")
    ax, ay = axn, ayn
    turn += 1

# did the game end within the 600 turns?
if not caught:
    print("AI was not caught within 600 turns.")
    sys.exit(0)

# check for trailing output
trailing = submission.stdout.readline().decode()
if trailing and not trailing.isspace():
    print("Your solution kept outputting things:")
    print(trailing)
    sys.exit(0)
