import java.io.FileNotFoundException;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

import java.util.*;
import java.io.*;

public class brothers{
    static int m, n, k;

    static Scanner scan;
    static PrintWriter out;
    public static void main(String[] args) throws FileNotFoundException{
        scan = new Scanner(new File("brothers.in"));
        out = new PrintWriter(new File("brothers.out"));
        m = scan.nextInt();
        n = scan.nextInt();
        
        BigInteger big = BigInteger.valueOf(m-1);
        BigInteger next = big.nextProbablePrime();
        System.out.println(big.toString()+" "+next.toString());
        BigInteger N = BigInteger.valueOf(n);
        BigInteger tw10 = BigInteger.valueOf(2010);
        int count = 0;
        while(next.compareTo(N)<=0){
            BigInteger Y = next.add(tw10);
            if(Y.isProbablePrime(32))count++;
            next = next.nextProbablePrime();
            //System.out.println(next.toString()+" "+N.toString());
        }
        System.out.println(count);
    }
    
}