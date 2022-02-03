import java.util.*;
public class bruted {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        loop:while(true){
            int truex = 4;
            int truey = 12;
            int startx = 0, starty = 0;
            int endx = 14, endy = 14;
            StringBuilder sb = new  StringBuilder();
            for(int i = 0;i<1;i++){
                int x1 = (int)(Math.random()*(endx-startx+1))+startx;
                int y1 = (int)(Math.random()*(endy-starty+1))+starty;
                int x2 = (int)(Math.random()*(endx-x1+1))+x1;
                int y2 = (int)(Math.random()*(endy-y1+1))+y1;
                boolean a = false, b=  false;;
                if(y2>=truey && y1<=truey){
                    a = true;
                    // the row is in our range
                    starty = y1;
                    endy = y2;
                }
                if(x2>=truex && y1<=truex){
                    b = true;
                    // the column is in our range
                    startx = x1;
                    endx = x2;
                }
                sb.append(x1+" "+y1+" "+x2+" "+y2+"\n");

            }
            //System.out.println(startx+" "+starty+" "+endx+" "+endy);
            if(startx == truex && endx == truex 
            && starty == truey && endy == truey){
                System.out.println(sb);
                break loop;
            }
        }
    }
}
