import java.util.*;
public class junk {
    static double[][] arr;
    static double ans;
    public static void main(String[] args){
        Scanner scan =new Scanner(System.in);
        int t = scan.nextInt();
        loop:while(t-->0){
            arr = new double[2][7];
            for(int i = 0;i<2;i++){
                for(int j = 0;j<7;j++){
                    arr[i][j] = scan.nextInt();
                }
            }
            int[] dir =new int[3];
            Arrays.fill(dir,1);
            for(int i = 4;i<7;i++){
                double diff = (arr[1][i]-arr[0][i]);
                //if(arr[1][i]<0)dir[i-4] = -1;
                arr[1][i] = dir[i-4]*diff;
            }
            double l = 0, r = 1e9+3;
            double sumR = arr[0][3]+arr[1][3];
            for(int i = 0;i<200;i++){
                double g1 = (l*2+r)/3;
                double g2 = (l+r*2)/3;
                
                //if finding min
                if(go(g1) > go(g2)) l = g1;
                else r = g2;
            }
            double dists = go(l);
            //System.out.println(dists);
            if(dists-1e-8>sumR){
                System.out.println("No collision");
                continue;
            }
            double ans = l;
            for(double i = l;i>=0;i-=0.0001){
                double dist = go(i);
                if(dist>sumR){
                    break;
                }
                ans = i;
            }

            System.out.printf("%.3f\n",ans);
            //System.out.println(dists+" "+l);
            
        }
        
    }
    static double go(double in){
        double x = arr[1][0]+arr[1][4]*in;
        double y = arr[1][1]+arr[1][5]*in;
        double z = arr[1][2]+arr[1][6]*in;
        double val = 0;
        double x1 = arr[0][0];
        double y1 = arr[0][1];
        double z1 = arr[0][2];
        val = Math.sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
        return val;
    }
}
