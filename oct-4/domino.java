import java.util.*;
import java.io.*;;
public class domino {
    static int n;
    static int[][][][][] dp;
    static Scanner scan;
    static PrintWriter out;
    static int[][] freq;
    public static void main(String[] args) throws FileNotFoundException{
        scan = new Scanner(new File("domino.in"));
        out = new PrintWriter(new File("domino.out"));
        n = scan.nextInt();
        int r = scan.nextInt();
        freq = new int[7][7];
        dp = new int[n+1][7][7][7][7];
        for(int i = 0;i<n;i++){
            int a = scan.nextInt();
            int b = scan.nextInt();
            int lower = Math.min(a,b);
            int higher = math.max(a,b);
            freq[lower][higher]++;

            for(int[][][][] ii:dp)
                for(int[][][] iii :ii)
                    for(int[][] iv:iii)
                        for(int[] v:iv)Arrays.fill(v,-1);
        }

    }
    static int go(int valL, int valR, int A,int B, int left){
        
    }
}
