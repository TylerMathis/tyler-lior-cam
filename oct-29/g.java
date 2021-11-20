import java.util.*;
public class g{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        long[] arr = new long[n];
        long[] next = new long[n];
        ArrayList<Long> list = new ArrayList<>();
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
            list.add(arr[i]);
        }
        int t = n-1;
        long ans = 0;
        while(t-->0){
            int idx = 0;
            long minC = Long.MAX_VALUE/2;
            for(int i = 0;i<list.size()-1;i++){
                if(list.get(i)+list.get(i+1)<minC){
                    idx = i;
                    minC = list.get(i)+list.get(i+1);
                }
            }
            //delete at minC and replace 
            ans+=minC;
            list.set(idx,minC);
            list.remove(idx+1);
            // System.out.println(ans+" "+minC);
            // for(Long in:list){
            //     System.out.println("heh "+in);
            // }
        }
        System.out.println(ans);
    }
}