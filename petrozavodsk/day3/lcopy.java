import java.io.PrintWriter;
import java.util.*;

public class lcopy {
    static ArrayList<Integer>[] adj;
    static HashSet<Integer> set;
    static boolean[] v;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter out =new PrintWriter(System.out);
        int n = scan.nextInt();
        int q = scan.nextInt();
        int[] a =new int[q];
        int[]b = new int[q];
        adj = new ArrayList[n];
        for(int i =0 ;i<n;i++){
            adj[i] =new ArrayList<>();
        }
        for(int i = 0;i<q;i++){
            a[i]= scan.nextInt()-1;
            b[i]= scan.nextInt()-1;
            adj[a[i]].add(b[i]);
        }
        set = new HashSet<>();
        v = new boolean[n];
        for(int i = 0;i<n;i++){
            if(adj[i].size() == 0)continue;
            for(Integer to:adj[i]){
                int one = i;
                int two = to;
                int bigDiff =  Math.abs(one+1-two);
                HashSet<Integer> fine = new HashSet<>();
                fine.add(bigDiff);
                dfs(i,bigDiff,new HashSet<>(),true);
            }
        }
        // System.out.println("SIZE "+set.size());
        if(set.size()==1 && set.contains(0)){
            System.out.println(n);
            for(int i = 1;i<=n;i++){
                System.out.print(i+" ");
            }
            System.out.println();
            return;
        }
        
        set.remove(0);
        set.add(1);
        System.out.println(set.size());
        for(Integer in:set){
            System.out.print(in+" ");
        }
        System.out.println();
        
    }
    static void dfs(int idx, int gcd,HashSet<Integer> loc, boolean good){
        // System.out.println("WAAAAAA "+idx+" "+gcd+" "+adj[idx].size());
        //if(v[idx])return;
        boolean pass = true;
        for(Integer to:adj[idx]){
            if(v[to])continue;
            pass = false;
            v[to] = true;
            int bigDiff = Math.abs(idx+1-to);
            loc.add(bigDiff);
            // System.out.println("hey "+gcd+" "+bigDiff);
            int gcdtrue = gcd(gcd,bigDiff);
            if(good && gcd == 1){
                gcdtrue = bigDiff;
                good = !good;
            }
            dfs(to,gcdtrue,loc,good);
            loc.remove(bigDiff);
            v[to] = false;
        }
        if(pass){
            // System.out.println(idx+" "+gcd);
            if(gcd==1 || gcd==-1)return;
            set.addAll(loc);
        }
    }
    static int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
}
