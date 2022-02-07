import java.util.*;
public class i{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();;
        int m = scan.nextInt();
        inter[] arr= new inter[n];
        for(int i = 0;i<n;i++){
            arr[i]= new inter(scan.nextInt(),scan.nextInt(),scan.nextInt());
        }
        Arrays.sort(arr);
        int[] values = new int[n];
        int left = arr[0].s;
        int right = arr[0].f;
        int height = n;
        for(int i = 0;i<n;i++){
            
            for(int j = left;j<=right;j++){
                values[j] = height;
                height--;
            }
            if(i==n-1)break;
            left = arr[i+1].s;
            right = arr[i+1].f;
        }
    }
    static class inter implements Comparable<inter>{
        int h, s, f;
        public inter(int h, int s, int f){
            this.h = h;
            this.s = s;
            this.f = f;
        }
        @Override
        public int compareTo(inter o){
            return o.h-h;
        }
    }
}