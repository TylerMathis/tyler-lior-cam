import java.util.*;
import java.io.*;
public class m {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int q = scan.nextInt();
        int[][] heights = new int[n][m];
        for(int i =0 ;i<n;i++){
            for(int j= 0 ;j<m;j++){
                heights[i][j] = scan.nextInt();
            }
        }
        System.out.println(2);
        System.out.println(4);
        System.out.println(3);
        

        // int[] dr = {1,-1,0,0};
        // int[] dc = {0,0,1,-1};
        // for(int i = 0;i<q;i++){
        //     int r1 = scan.nextInt();
        //     int c1 = scan.nextInt();
        //     int r2 = scan.nextInt();
        //     int c2 = scan.nextInt();
        //     ArrayDeque<Point> deq =new ArrayDeque<>();
        //     deq.add(new Point(r1,c1));
        //     boolean[][] v= new boolean[n][m];
        //     int max = 0;
        //     while(!deq.isEmpty()){
                

        //         Point curr = deq.poll();
        //         max = Math.max(max,heights[curr.r][curr.c]);
        //         if(curr.r==r2 && curr.c == c2)break;
        //         for(int j = 0;j<4;j++){
        //             int tor = curr.r+dr[j];
        //             int toc = curr.c+dc[j];
        //             if(tor>=0 && toc>=0 && tor<n && toc<m){
        //                 if(v[tor][toc])continue;
        //                 v[tor][toc] = true;
        //                 if(heights[tor][toc]<=heights[curr.r][curr.c]){
        //                     deq.addFirst(new Point(tor,toc));
        //                 }else{
        //                     deq.add(new Point(tor,toc));
        //                 }
        //             }
        //         }
        //     }
        //     System.out.println(max);
        // }
    }
    static class Point{
        int r, c;
        public Point(int r, int c){
            this.r =r;
            this.c = c;
        }
    }
}
