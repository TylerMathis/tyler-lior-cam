import java.util.*;
public class j{
    static long[][] dp;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k=  scan.nextInt();
        dp = new long[n][k];
        for(int i = 0;i<n;i++)Arrays.fill(dp[i],-1);
    }
    static long go(int idx, int need){
        if(dp[idx][need]!=-1)return dp[idx][need];
        
    }
}