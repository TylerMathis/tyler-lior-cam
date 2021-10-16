import java.util.*;
import java.io.*;
public class f{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int max = 2_000_001;
        boolean[] isPrime = new boolean[max];
        Arrays.fill(isPrime,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i<Math.sqrt(max)+1;i++){
            if(isPrime[i]){
                for(int j = i*2;j<max;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int n = scan.nextInt();
        int[] arr =new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
        }
        int[] freq= new int[max];
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=Math.sqrt(arr[i]);j++){
                if(arr[i]%j==0){
                    freq[j]++;
                    if((arr[i]/j)!=j){
                        freq[arr[i]/j]++;
                    }
                }
            }
        }
        // for(int i = 0;i<100;i++){
        //     System.out.println(i+" "+freq[i]);
        // }
        int count = 0;
        long maxV=  -1;
        for(int i = 2;i<max;i++){
            //if(isPrime[i]){
                count++;
                for(int j = 2;j<=20;j++){
                    long val = (long)Math.pow(i,j);
                    if(val>1e6)break;
                    
                    if(freq[(int)val]==n)maxV = Math.max(maxV,(int)val);
                }
            //}
        }
        if(maxV==-1){
            System.out.println("NO CIVIL WAR");
        }else
        System.out.println(maxV);
    }
}