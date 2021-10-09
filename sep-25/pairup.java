import java.util.Scanner;
import java.util.*;
public class pairup {
    static int n, m;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        Integer[] y= new Integer[n];
        HashMap<Integer,Integer> freq = new HashMap<>();
        for(int i = 0;i<n;i++){
            int a = scan.nextInt();
            int b=  scan.nextInt();
            freq.put(b,a);
            y[i] = b;
        }
        Arrays.sort(y);
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<=r){
            if(l==r){
                if(freq.get(y[l])>=2)
                    ans = Math.max(y[l]*2,ans);
                break;
            }
            int right = freq.get(y[r]);
            int left = freq.get(y[l]);

            int min = Math.min(right,left);
            freq.put(y[r],freq.get(y[r])-min);
            freq.put(y[l],freq.get(y[l])-min);
            ans = Math.max(y[l]+y[r],ans);
            if(freq.get(y[l])==0){
                l++;
            }
            if(freq.get(y[r])==0){
                r--;
            }
            //System.out.println(l+" "+r+" "+freq.get(y[l])+" "+freq.get(y[r]));
        }
        System.out.println(ans);
    }
}
