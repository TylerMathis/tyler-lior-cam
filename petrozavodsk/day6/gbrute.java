import java.util.ArrayList;
import java.util.Scanner;

public class gbrute{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int ini = n;
        n = (int)(Math.pow(2,n));
        int[] a = new int[n];
        for(int i =0 ;i<n;i++){
            a[i] = scan.nextInt();
        }
        int[] vals =new int[n];
        for(int i = 0;i<n;i++){
            ArrayList<Integer> indices = new ArrayList<>();
            for(int j =0 ;j<n;j++){
                int bits = i&j;
                String s = Integer.toBinaryString(bits);
                int ones = 0;
                for(int k = 0;k<s.length();k++){
                    if(s.charAt(k)=='1')ones++;
                }
                if(ones%2==1){
                    vals[i]+=a[j];
                    indices.add(j);
                }
            }
            System.out.println("current i: "+i);
            System.out.println("Binary String: "+ Integer.toBinaryString(i));
            for(Integer in:indices){
                String now = Integer.toBinaryString(in);
                while(now.length()<ini)now = "0"+now;
                System.out.print(now+"\n");
            }
            System.out.println("Indices");
            for(Integer in:indices){
                System.out.print(in+" ");
            }
            System.out.println("\n");
        }
        for(Integer in:vals){
            System.out.print(in+" ");
        }
    }
}