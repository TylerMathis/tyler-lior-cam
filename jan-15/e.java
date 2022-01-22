import java.util.Scanner;

public class e {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t-->0){
            long b = scan.nextInt();
            long d = scan.nextLong();
            long gcd = gcd(b,d);
            System.out.println(gcd);
            long start = gcd;
            //long c = (long) (d * ((double) b / d - (double) start / b));
            long c = (long)(1.0*d*(b*1.0/d-start*1.0/b)+ 1e-6);
            System.out.println(start+" "+c);
            
        }
    }
    static long gcd(long a, long b){
        if(b == 0)return a;
        return gcd(b,a%b);
    }
    
}
