import java.util.Scanner;
import java.util.*;
public class hps {
    static int n, k;
    static int[][][] dp;
    static int[] s;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        k = scan.nextInt()+1;
        dp = new int[n][k][3];
        s=  new int[n];
        for(int i = 0;i<n;i++){
            char aa = scan.next().charAt(0);
            //System.out.println(aa);
            if(aa=='H')s[i] = 0;
            if(aa=='P')s[i] = 1;
            if(aa=='S')s[i] = 2;
            for(int j = 0;j<k;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        int ans = 0;
        for(int i = 0;i<=2;i++){
            ans = Math.max(ans,go(0,0,i));
        }
        System.out.println(ans);

    }
    static int go(int idx, int changes, int curr){
        
        if(idx==n)return 0;
        if(dp[idx][changes][curr]!=-1)return dp[idx][changes][curr];
        int max = 0;
        if(s[idx]==0 && curr==1){
            max = 1 + go(idx+1,changes,curr);
        }else if(s[idx]==1 && curr==2){
            max = 1 + go(idx+1,changes,curr);
        }else if(s[idx] == 2 && curr==0){ 
            max = 1 + go(idx+1,changes,curr);
        }
        else{
            //if statement block: change to win this one
            if(changes<k-1){
                if(s[idx]==0){
                    //change to 1
                    max = 1 + go(idx+1,changes+1,1);
                }else if(s[idx]==1){
                    //change to 2
                    max = 1 + go(idx+1,changes+1,2);
                }else{
                    //change to 0 
                    max = 1 + go(idx+1,changes+1,0);
                }
            }
            //dont change, and lose
            
            max = Math.max(max,go(idx+1,changes,curr));
        }
        //System.out.println(idx+" "+changes+" "+curr +" "+max);
        return dp[idx][changes][curr] = max;
    }

}
