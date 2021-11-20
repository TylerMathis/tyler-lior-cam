import java.util.*;

public class f{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n =scan.nextInt();
        int[] fib = new int[40];
        fib[0] = 0;
        fib[1] = 1;
        HashMap<Integer, Integer> ori = new HashMap<>();
        int[] idx1 = new int[1_000_001];
        int[] idx2 = new int[1_000_001];
        Arrays.fill(idx1,-1);
        Arrays.fill(idx2,-1);
        for(int i = 0;i<40;i++){
            if(i<2){
                ori.put(fib[i],i);
                continue;
            }
            fib[i] = fib[i-1]+fib[i-2];
            ori.put(fib[i],i);
            if(fib[i]>1e8)break;
        }
        int[] arr =new int[n];
        for(int i = 0;i<n;i++){
            arr[i] =scan.nextInt();
            if(idx1[arr[i]]!=-1)idx2[arr[i]] = i;
            else idx1[arr[i]] = i;
        }
        for(int i = 0;i<n;i++){
            if(!ori.containsKey(arr[i]))continue;
            int at = ori.get(arr[i]);
            if(at>0){
                int need = at-1;
                //we cant use the same index for 1 1 btw
                if(fib[need]==arr[i]){
                    int to = idx2[arr[i]];
                    if(to==-1)continue;
                    System.out.println((idx1[arr[i]]+1)+" "+(idx2[arr[i]]+1));
                    return;
                }else{
                    int to = idx1[fib[need]];
                    if(to==-1)continue;
                    System.out.println((to+1)+" "+(i+1));
                    return;
                }
            }
        }
        System.out.println("impossible");        
    }
}