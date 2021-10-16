import java.util.*;
public class aa {
    static long l;
    static int a, b, t, r;
    static int n;
    static double[] arr;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        l = scan.nextLong();
        a = scan.nextInt();
        b = scan.nextInt();
        t = scan.nextInt();
        r = scan.nextInt();
        n = scan.nextInt();
        arr = new double[n];
       
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextLong();
        }
        double boost = 0;
        double ans = 0;
        for(int i = 0;i<n;i++){
            double next = l;
            if(i<n-1){
                next = arr[i+1];
            }
            double diff = next-arr[i];
            //how long does it take us to cover diff distance with the current boost in the pack
            double initBoost = boost;
            double distance = diff;
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
            //if we can finish this in less than boost time don't buy
            if(boostLeft>0){
                ans+=timeDontDrink;
            }else{
                ans+=timeDontDrink;
            }
            double time = 0;
            if(boost)
            if(diff/a<=r){
                boost = n+r;
                ans+=diff/a;
                continue;
            }else{}

        }
        /*
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
        */
        System.out.println(ans);
    }
}
