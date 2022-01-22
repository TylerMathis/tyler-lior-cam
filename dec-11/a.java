import java.util.Scanner;

import java.util.*;
public class a {
    static int[] dp;
    static int n;
    static ArrayList<Integer>[] adj;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        int n = scan.nextInt();
        adj = new ArrayList[n];
        for(int i = 0;i<n;i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0;i<n-1;i++){
            int a = scan.nextInt();
            int b = scan.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        
    }
    static class state{
        int idx, from;
        public state(int idx, int from){
            this.idx = idx;
            this.from = from;
        }
    }
}
