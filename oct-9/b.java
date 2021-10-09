import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] board = new int[n][n];
        int sum = 0;
        for(int i = 0;i<n-1;i++){
            board[0][i] = 100_000+i+1;
            sum+=(i+1);
            String down = Integer.toString(i+1);
            down+="00001";
            board[i][0] = Integer.parseInt(down);
        }
        
        board[0][n-1] = 100_000+sum;
        String down = Integer.toString(sum);
        down+="00001";
        board[n-1][0] = Integer.parseInt(down);
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         System.out.print(board[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        for(int i = 1;i<n;i++){
            for(int j = 1;j<n;j++){
                board[i][j] = board[i-1][j]+board[i][j-1]-board[i-1][j-1];
            }
        }
        if(n==2){
            System.out.println(-1);
            return;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
