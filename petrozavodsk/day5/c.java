import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class c {
    static ArrayList<Integer>[] adj;
    static long[][] dp;
    public static void main(String[] args) throws IOException{
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        //Scanner scan = new Scanner(System.in);

        int n = Integer.parseInt(scan.readLine());
        adj = new ArrayList[n];
        dp = new long[n][2];
        for(int i = 0;i<n;i++){
            adj[i] = new ArrayList<Integer>();
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        for(int i = 0;i<n-1;i++){
            String[] s = scan.readLine().split(" ");
            int a = Integer.parseInt(s[0])-1;
            int b = Integer.parseInt(s[1])-1;
            adj[a].add(b);
            adj[b].add(a);
        }
        int start = 0;
        for(int i = 0;i<n;i++){
            if(adj[i].size()==1)start = i;
        }
        System.out.println(go(start,0,-1));
        
    }
    static long go(int idx, int parity,int parent){
        if(parent!=-1){
            if(adj[idx].size()==1 && parity == 1)return Integer.MAX_VALUE;
            else if(adj[idx].size()==1)return 0;
        }
        if(dp[idx][parity]!=-1)return dp[idx][parity];
        int min = Integer.MAX_VALUE;
        int sum = 0;
        for(Integer to:adj[idx]){
            if(to == parent)continue;
            sum += Math.min(go(to,parity^1,idx), go(to,parity,idx) + 1);
        }
        return dp[idx][parity] = sum;
    }

}
