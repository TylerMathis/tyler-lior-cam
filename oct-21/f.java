import java.util.*;
public class f {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a= new int[n];
        int[] b= new int[n];
        int[] freqa= new int[ 1001];
        int[] freqb= new int[1001];
        for(int i = 0;i<n;i++){
            a[i] = scan.nextInt();
            b[i] = scan.nextInt();
            freqa[a[i]]++;
            freqb[b[i]]++;

        }
        long[] ca = new long[1002];
        long[] cb = new long[1002];
        int count = 0;
        for(int i = 1000;i>=0;i--){
            ca[i] = count;
            count+=freqa[i];
        }

        count = 0;
        for(int i = 1000;i>=0;i--){
            cb[i] = count;
            count+=freqb[i];
        }
        long ans = 0;
        int[] times = new int[n];
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=1000;j++){
                if(a[i]+j>1000 || b[i]+j>1000)break;
                int idx1 = a[i]+j;
                int idx2 = b[i]+j;
                long min = Math.min(ca[idx1],cb[idx2]);
                ans+=min;
            }
        }
        System.out.println(ans);
    }
}
