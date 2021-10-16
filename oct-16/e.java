import java.util.PriorityQueue;
import java.util.*;

public class e {
    static int h, w;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        h = scan.nextInt();
        w = scan.nextInt();
        int[][] arr = new int[h][w];
        for(int i = 0;i<h;i++){
            for(int j=  0;j<w;j++){
                arr[i][j] = scan.nextInt()*-1;
            }
        }
        int r = scan.nextInt()-1;
        int c = scan.nextInt()-1;
        int[][] best =new int[h][w];
        for(int i = 0 ;i<h;i++){
            Arrays.fill(best[i],-1);
        }
        best[r][c] = arr[r][c];
        PriorityQueue<state> pq = new PriorityQueue<>();
        pq.add(new state(r,c,arr[r][c]));
        
        while(!pq.isEmpty()){
            state curr = pq.poll();
            int i = curr.r;
            int j = curr.c;
            //System.out.println(i+" "+j);
            for(int k = i-1;k<=i+1;k++){
                for(int l = j-1;l<=j+1;l++){
                    if(inBoinds(k,l)){
                        if(arr[k][l]<0)continue;
                        if(best[k][l]<0){
                            best[k][l] = Math.min(arr[k][l],best[i][j]);
                            pq.add(new state(k,l,best[k][l]));
                        }
                    }
                }
            }
        }
        long ans = 0;
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(arr[i][j]<0 || best[i][j]<0)continue;
                ans+=best[i][j];
            }
        }
        System.out.println(ans);
    }
    static class state implements Comparable<state>{
        int r, c;
        int cost;
        public state(int r, int c, int cost){
            this.r = r;
            this.c = c;
            this.cost = cost;
        }
        @Override
        public int compareTo(state o){
            return o.cost-cost;
        }
    }
    static boolean inBoinds(int r, int c){
        if(r>=0 && c>=0 && r<h && c<w)return true;
        return false;
    }
    
}
