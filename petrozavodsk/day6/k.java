import java.io.PrintWriter;
import java.util.*;
public class k {
    static int n, x, y;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        n = 10;
        boolean[][] v =new boolean[2*n+1][2*n+1];
        boolean[][] edge = new boolean[2*n+1][2*n+1];
        for(int i = 0;i<=n*2;i++){
            for(int j = 0;j<=n*2;j++){
                if((i == 0 && j == n*2-1) || (j == 0 && i == n*2-1)){
                    edge[i][j] = true;
                }
            }
        }
        v[n][n] = true;
        x = scan.nextInt()+9; y = scan.nextInt()+9;
        int[] dx = {1,1,1,-1,-1,-1};
        int[] dy = {1,0,-1,1,0,-1};
        while(true){
            boolean good = false;
            for(int i = 0;i<6;i++){
                int tox = x+dx[i];
                int toy = y+dy[i];
                if(valid(tox,toy,v))good = true;
            }
            if(!good)return;
            // find the closest point
            ArrayDeque<Point> deq =new ArrayDeque<>();
            deq.add(new Point(x, y,0,0,0));
            int closex = 0, closey = 0, distance =0 ;
            boolean[][] tempV = new boolean[v.length][v[0].length];
            for(int i = 0;i<v.length;i++){
                for(int j = 0;j<v[0].length;j++){
                    tempV[i][j] = v[i][j];
                }
            }
            //System.out.println(deq.poll().x);
            loop:while(true){
                Point curr = deq.poll();
                for(int i = 0;i<6;i++){
                    int tox = curr.x+dx[i];
                    int toy = curr.y+dy[i];
                    if(valid(tox,toy,tempV)){
                        if(edge[tox][toy]){
                            closex = tox;
                            closey = toy;
                            distance = curr.dist+1;
                            break loop;
                        }
                        tempV[tox][toy] = true;
                        deq.add(new Point(tox,toy,curr.dist+1,0,0));
                    }
                }
            }
            tempV = new boolean[v.length][v[0].length];
            for(int i = 0;i<v.length;i++){
                for(int j = 0;j<v[0].length;j++){
                    tempV[i][j] = v[i][j];
                }
            }

            deq.clear();
            deq.add(new Point(closex,closey,0,0,0));
            Point[] arr =new Point[200];
            arr[0] = new Point(closex,closey,0,0,0);
            int index = 0;
            Point one = new Point(-1,-1,-1,-1,-1);
            Point two = new Point(-1,-1,-1,-1,-1);
            loop:while(!deq.isEmpty()){
                Point curr= deq.poll();
                for(int i = 0;i<6;i++){
                    int tox = curr.x+dx[i];
                    int toy = curr.y+dy[i];
                    if(tox<0 || toy < 0 || tox>=x && toy>=y)continue;
                    if(!edge[tox][toy])continue;
                    if(v[tox][toy]){
                        //closest one we found
                        int placeAtDist = (curr.dist+1)/2;
                        Point at = new Point(tox,toy,curr.dist+1,curr.par,index);
                        while(at.dist>placeAtDist){
                            at = arr[at.par];
                        }
                        if(one.x == -1){
                            one = at;
                        }else{
                            two = at;
                            if(two.dist>one.dist){
                                v[two.x][two.y] = true;
                                out.println(two.x+" "+two.y);
                                out.flush();
                            }else{
                                v[one.x][one.y] = true;
                                out.println(one.x+" "+one.y);
                                out.flush();
                            }
                        }
                    }else if(curr.dist+1 == distance){
                        if(one.x == -1){
                            //place here
                            v[tox][toy] = true;
                            out.println(tox+" "+toy);
                            out.flush();;
                        }else{
                            v[one.x][one.y] = true;
                            out.println(one.x+" "+one.y);
                            out.flush();
                        }
                    }
                    if(tempV[tox][toy])continue;
                    arr[index] = new Point(tox,toy,curr.dist+1,curr.idx,index);
                    index++;
                }
            }
            
            x = scan.nextInt()+9;
            y = scan.nextInt()+9;
            if(edge[x][y])return;
            
            
        }

    }

    static class Point{
        int x, y, dist, par, idx;
        public Point(int x, int y, int dist,int par, int idx){
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.par = par;
            this.idx = idx;
        }
    }
    static boolean valid(int xPos, int yPos, boolean[][] v){
        if(xPos>=0 && yPos>=0 && xPos<x && yPos<y && !v[xPos][yPos])return true;
        return false;
    }
}
