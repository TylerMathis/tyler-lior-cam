import java.util.*;
public class d{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        int[] b=  new int[n];
        for(int i = 0;i<n;i++){
            a[i]= scan.nextInt();
            b[i] = scan.nextInt();
        }

        int[] v = new int[n];
        for(int i = 0;i<n;i++){
            int moves = 0;
            while(a[i]!=0){
                long currVal = 1;
                while(currVal*b[i]<=a[i]){
                    currVal*=b[i];
                }
                long div = a[i]/currVal;
                moves+=div;

                //System.out.println(i+" "+a[i]+" "+currVal+" "+div+" "+moves);
                a[i]-=currVal*div;
            }
            //System.out.println(moves);
            //v[i] = moves;
            v[i] = moves%2;
            if(v[i] == 1){
                //System.out.println(v[i]+" Alice won this pile");
            }
        }
        int count = 0;
        int xor = 0;
        for(int i = 0;i<n;i++){
            count+=v[i];
            xor^=v[i];
        }
        if(xor==0){
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }
        System.out.println("count "+count);
    }
}