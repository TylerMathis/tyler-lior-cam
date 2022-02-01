import java.util.*;
import java.io.*;

class b {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        char[][] board = new char[n][n];
        for(int i = 0;i<n;i++){
            Arrays.fill(board[i],'W');
        }
        int pos = n-1;
        while(pos>0){
            board[pos][pos] = 'B';
            for(int i = 0;i<pos-1;i++){
                board[pos][i] = 'B';
                board[i][pos] = 'B';
            }
            pos-=2;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }

    }
}