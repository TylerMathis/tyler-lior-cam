import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import java.util.*;
import java.io.*;

public class munich{
    static long[][] dp;
    static int m, n, k;
    static long[] p, q;
    static Scanner scan;
    static PrintWriter out;
    public static void main(String[] args) throws FileNotFoundException{
        scan = new Scanner(new File("munich.in"));
        out = new PrintWriter(new File("munich.out"));
        m = scan.nextInt();
        n = scan.nextInt();
        k = scan.nextInt();
        //m*=k;
        //n*=k;
        p = new long[3];
        q = new long[3];
        for(int i = 0;i<3;i++)p[i] = scan.nextInt();
        for(int i = 0;i<3;i++){
            q[i] = scan.nextInt();
            q[i] = Math.min(q[i],p[i]*3);
        }
        
        dp = new long[m+1][n+1];
        for(int i = 0;i<=m;i++){
            Arrays.fill(dp[i],-1);
        }
        //System.out.println(go(m,n));
        out.println(go(m,n));
        out.flush();
        out.close();;

    }
    static long go(int adults, int children){
        if(adults<=0 && children <= 0)return 0;
        if(dp[adults][children]!=-1)return dp[adults][children];
        long best = Integer.MAX_VALUE;
        if(adults>0){
        best = Math.min(best,q[0]+go(adults-1,children));
        }
        if(children>0){
            best = Math.min(best,q[1]+go(adults,children-1));
            best = Math.min(best,q[0]+go(adults,children-1));
        }
        for(int i = 0;i<=5;i++){
            if(i==0 && children==0)continue;
            if(i==5 && adults==0)continue;
            best = Math.min(best,q[2]+go(adults-Math.min(i,adults),children-Math.min(children,(5-i)*2)));
        }
        return dp[adults][children] = best;
        
    }
}