import java.util.*;
import java.io.*;
public class c {

    static int n;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        PrintWriter out =new PrintWriter(System.out);
        n = scan.nextInt();
        int x1 = scan.nextInt(),y1 =scan.nextInt(),x2 = scan.nextInt(),y2 =scan.nextInt();
        //agent x, agent y
        int ax = scan.nextInt();
        int ay = scan.nextInt();
        int[] dx = {1,-1,0,0};
        int[] dy = {0,0,-1,1};
        while(true){

            int distx = Math.abs(x1-ax);
            int disty = Math.abs(y1-ay);
            if(distx>=disty){
                if(ax>x1){
                    x1++;
                }else{
                    x1--;
                }
            }else{
                if(ay>y1){
                    y1++;
                }else{
                    y1--;
                }
            }
            out.println(x1+" "+y1+" "+x2+" "+y2);
            out.flush();
            ax = scan.nextInt();
            ay = scan.nextInt();
            if(ax==0 && ay==0)return;
        }

    }
    static boolean inBoinds(int x, int y){
        return(x>=0 && y>=0 && x<n && y<n);
    }
    
}
