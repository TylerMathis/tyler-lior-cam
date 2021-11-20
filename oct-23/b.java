import java.util.*;

public class b {
    static int[][] dp;
    static int n;
    static int width;
    static int height;
    static int[] w, h;
    static int[] pref;
    static int max;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        width = scan.nextInt();
        height = scan.nextInt();
        w = new int[n];
        h = new int[n];
        dp = new int[n][width+1];
        pref= new int[n];
        max = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            w[i]= scan.nextInt();
            h[i]= scan.nextInt();
            max = Math.max(max,h[i]);
            pref[i] = sum;
            sum+=w[i];
            
            Arrays.fill(dp[i],-1);
        }
        int check = go(0,0);
        if(max <= height && check==1){

            if(max==height){
                System.out.println(-1);
            }else{
                System.out.println(max);
            }
        }else{
            System.out.println("impossible");
        }

    }
    static int go(int idx ,int bottomFil){
        if(idx==n)return 1;
        if(dp[idx][bottomFil]!=-1)return dp[idx][bottomFil];
        int top = pref[idx]-bottomFil;
        int best = 0;
        if(width-bottomFil>=w[idx] && h[idx] <= max){
            //we can put it here
            best|=go(idx+1,bottomFil+w[idx]);
        }if(width-top>=w[idx] && h[idx] <= height - max){
            //we can put it up
            best|=go(idx+1,bottomFil);
        }
        return dp[idx][bottomFil] = best;
    }
}
