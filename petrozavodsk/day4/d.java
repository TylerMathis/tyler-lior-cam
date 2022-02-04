import java.util.*;
public class d{
    static int[][][] dp;
    static char[][] board;
    static int n, m;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt(); m = scan.nextInt();
        board = new char[n][m];
        dp = new int[n][m][2];
        for(int i = 0;i<n;i++){
            board[i] = scan.next().toCharArray();
            for(int j = 0;j<m;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        int ans = 0;
        ans = go(0,0,0);
        System.out.println(ans);

    }
    static int go(int row, int col, int count){
        if(col >= m-1)return 0;
        if(row >= n-1)return 0;
        if(col < 0)return 0;
        if(dp[row][col][count]!=-1)return dp[row][col][count];
        int counts = 0;
        for(int i = row;i<=row+1 && i < n;i++){
            for(int j = col;col<=col+1 && j<m;j++){
                if(board[i][j] == '#')counts++;
            }
        }
        int best = Integer.MAX_VALUE;
        //always consider not taking
        //consider not taking
        best = go(row, col+1,0);
        if(counts>0){
            // consider taking
            if(col+2>=m-1){
                best = Math.min(best,1+go(row,col+2,counts));
            }
            best = Math.min(best,1+go(row,col+2,counts));
            best = Math.min(best,1+go(row+2,col-1,counts));
        }
        return dp[row][col][count] = best;
    }
}