import java.util.*;
public class brute{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int b = scan.nextInt();
        int d = scan.nextInt();

        int count =0 ;
        for(int a = 1;a<=1000;a++){
            for(int c = 1;c<=1000;c++){
                double aa = a;
                double bb = b;
                double cc = c;
                double dd = d;
                if(aa/bb + cc/dd +1e-6 > bb/dd && aa/bb + cc/dd -1e-6 < bb/dd){
                    System.out.println(a+" "+c);
                    count++;
                }
                
            }
        }
        System.out.println(b+" "+d+" "+count);
    }
}