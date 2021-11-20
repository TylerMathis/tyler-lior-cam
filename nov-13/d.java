import java.util.Scanner;

public class d {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n =scan.nextInt();
        int[] arr =new int[n];
        int ans = 0;
        for(int i = 0;i<n;i++){
            arr[i]= scan.nextInt();
        }
        ans = arr[0]+1;
        for(int i = 0;i<n-1;i++){
            int diff = arr[i]-arr[i+1];
            if(diff<=0)continue;
            ans-=diff;
        }
        ans = Math.max(ans,0);
        System.out.println(ans);
    }
}
