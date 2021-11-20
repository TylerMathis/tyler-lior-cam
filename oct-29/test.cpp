#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct LLnode
{
    LLnode *next;
    int val;
    LLnode(int v) : next(NULL), val(v) {}
};

// reverse runs of even valued nodes in a linked list
LLnode *reverseRunsOfEvens(LLnode *head)
{
    LLnode *evenHead = NULL;
    LLnode *evenTail = NULL;
    LLnode *oddHead = NULL;
    LLnode *oddTail = NULL;
    LLnode *curr = head;
    while (curr != NULL)
    {
        LLnode *next = curr->next;
        curr->next = NULL;
        if (curr->val % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                evenTail = evenHead;
            }
            else
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                oddTail = oddHead;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = next;
    }
    if (evenHead == NULL)
    {
        return oddHead;
    }
    else
    {
        evenTail->next = oddHead;
        return evenHead;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    LLnode *head = new LLnode(1);
    vector<int> values = {2,4,2,8,11};

    LLnode *cur = head;
    for (int val : values)
    {
        LLnode *newNode = new LLnode(val);
        cur->next = newNode;
        cur = newNode;
    }

    LLnode *newHead = reverseRunsOfEvens(head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}
