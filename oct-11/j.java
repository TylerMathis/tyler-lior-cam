import java.util.*;
import java.io.*;
public class j{
    public static void main(String[] args) throws IOException{
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        String[] line1 = scan.readLine().split(" ");
        int n=  Integer.parseInt(line1[0]);
        int k = Integer.parseInt(line1[1]);
        int[] first =new int[k];
        int[] arr =new int[n];
        String[] line2 = scan.readLine().split(" ");
        Arrays.fill(first,-1);
        for(int i = 0;i<n;i++){
            int at = Integer.parseInt(line2[i])-1;
            arr[i] = at;
            if(first[at]==-1)first[at] = i;
        }
        long ans = 1;
        int at = first[0];
        for(int i = 1;i<k;i++){
            if(first[i]>at){
                ans+=first[i]-at;
            }else{
                ans+=n-at;
                ans+=first[i];
                
            }
            at = first[i];
        }
        System.out.println(ans);
    }
}