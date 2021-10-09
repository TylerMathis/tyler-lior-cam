import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import java.util.*;
import java.io.*;

public class express implements Runnable{
    static long[][][] dp;
    static long mod;
    static int n;
    static Scanner scan;
    static PrintWriter out;
    public static void main(String[] args) throws FileNotFoundException{
        scan = new Scanner(new File("express.in"));
        out = new PrintWriter(new File("express.out"));
        new Thread(null,new express(),"threadname",(1L<<30)).start();
    }
    public void run(){
        //Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        mod = scan.nextLong();
        //mod = 10999;
        dp = new long[n][3][2];
        for(long[][] curr:dp){
            for(long[] e :curr){
                Arrays.fill(e,-1);
            }
        }
        //System.out.println(go(0,0,0));
        out.println(go(0,0,0));
        out.flush();
        out.close();
    }
    static long go(int idx, int taken,int start){
        if(idx>=n)return 0 ;
        if(dp[idx][taken][start] !=-1)return dp[idx][taken][start];
        long count = 0;
        //System.out.println("heh "+idx+" "+taken+" "+start);
        if(taken>=1 && !(idx==n-1 && start==1)){
            //System.out.println(idx+" "+taken+" "+start);
            count+= (1+go(idx+2,2,start))%mod;
            count%=mod;
        }
        else{
            count+=(go(idx+2,1,idx==0? 1:0))%mod;
            count%=mod;
        }
        count+=go(idx+1,taken,start)%mod;
        count%=mod;
        return dp[idx][taken][start] = count;
    }
}