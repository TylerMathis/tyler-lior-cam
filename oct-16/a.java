import java.util.*;
public class a {
    static long l;
    static int a, b, t, r;
    static int n;
    static double[] arr;
    static double[][] dp;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        l = scan.nextLong();
        a = scan.nextInt();
        b = scan.nextInt();
        t = scan.nextInt();
        r = scan.nextInt();
        n = scan.nextInt();
        arr = new double[n];
        dp = new double[n][r+t];
        for(int i = 0;i<n;i++){
            Arrays.fill(dp,-1);
            arr[i] = scan.nextLong();
        }
        double ans = go(0,0) + arr[0]/a;
        System.out.println(ans);
    }
    static double go(int idx, int boost){
        if(idx==n)return 0;
        //TODO
        if(dp[idx][boost]!=-1)return dp[idx][boost];
        double bestT = Long.MAX_VALUE;
        double next = l;
        if(idx<n-1){
            next = arr[idx+1];
        }
        //determine time to next if we don't drink now
        double initBoost = boost;
        double distance = next-arr[idx];
        double wait = Math.max(0,boost-r);
        double distSlow = wait*a;
        double fast = Math.min(t,boost);
        double distFast = fast*b;
        double boostLeft = boost;

        double timeDontDrink = 0;
        //can we cover the distance slogging over?
        if(distSlow>=distance){
            boostLeft-=distance/a;
            distance = 0;
        }else{
            boostLeft-=wait;
            distance-=distSlow;
            if(distFast>=distance){
                boostLeft-=distance/b;
                distance = 0;
            }else{
                distance-=distFast;
                boostLeft = 0;
            }
        }
        timeDontDrink = boost-boostLeft + distance/a;
        double add = go(idx+1,boostLeft)+timeDontDrink;

        //determine time to next if we drink now
        double timeDrink = 0;
        boost = r+t;
        initBoost = boost;
        distance = next-arr[idx];
        wait = Math.max(0,boost-r);
        distSlow = wait*a;
        fast = Math.min(t,boost);
        distFast = fast*b;
        boostLeft = boost;

        if(distSlow>=distance){
            boostLeft-=distance/a;
            distance = 0;
        }else{
            boostLeft-=wait;
            distance-=distSlow;
            if(distFast>=distance){
                boostLeft-=distance/b;
                distance = 0;
            }else{
                distance-=distFast;
                boostLeft = 0;
            }
        }
        timeDrink = boost - boostLeft + distance/a;

        add = Math.min(add,go(idx+1,r+t)+timeDrink);
        return dp[idx][boost] = add;
    }
    static class state{
        double time;
        state from;
        public state(double time, state from){
            this.time = time;
            this.from = from;
        }
    }
}
