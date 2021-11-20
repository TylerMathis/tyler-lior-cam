import java.util.*;

public class k {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int m = scan.nextInt();
        int c = scan.nextInt();
        HashMap<Integer, Integer> compressx = new HashMap<>();
        HashMap<Integer, Integer> compressy = new HashMap<>();
        HashMap<Integer, Integer> backx = new HashMap<>();
        HashMap<Integer, Integer> backy = new HashMap<>();
        int[] x = new int[m+c];
        int[] y=  new int[m+c];
        int[] x1 = new int[m];
        int[] y1 = new int[m];
        int[] cx1 = new int[c];
        int[] cy1 = new int[c];
        for(int i = 0 ;i<m;i++){
            x[i] = scan.nextInt();
            y[i]= scan.nextInt();
            x1[i] = x[i];
            y1[i]=  y[i];
        }
        for(int i = 0;i<c;i++){
            x[i+m] = scan.nextInt();
            y[i+m]= scan.nextInt();
            cx1[i] = x[i+m];
            cy1[i]=  y[i+m];
        }
        Arrays.sort(x);
        Arrays.sort(y);
        for(int i = 0;i<m+c;i++){
            compressx.put(x[i],i);
            compressy.put(y[i],i);
            backx.put(i,x[i]);
            backy.put(i,y[i]);
        }
        for(int i = 0;i<m;i++){
            x1[i] = compressx.get(x1[i]);
            y1[i] = compressy.get(y1[i]);
        }
        for(int i = 0;i<c;i++){
            cx1[i] = compressx.get(cx1[i]);
            cy1[i] = compressy.get(cy1[i]);
        }
        int[] freqx = new int[m+c+1];
        int[] freqy = new int[m+c+1];
        for(int i = 0;i<m;i++){
            freqx[x1[i]]++;
            freqy[y1[i]]++;
        }
        
        int[] offx = new int[m+c+1];
        int[] offy = new int[m+c+1];
        boolean[][] oc = new boolean[offx.length][offy.length];
        for(int i = 0;i<c;i++){
            if(freqx[cx1[i]]+freqy[cy1[i]]==1){
                oc[cx1[i]][cy1[i]] = true;
                offx[cx1[i]]++;
                offy[cy1[i]]++;
                
            }
        }
        int best = 0;
        int bestx = 0;
        int besty = 0;
        for(int i = 0;i<offx.length;i++){
            for(int j = 0;j<offy.length;j++){
                int sum = offx[i]+offy[j];
                if(oc[i][j])sum--;
                if(sum>best){
                    bestx = i;
                    besty = j;
                    best = sum;
                }
            }
        }
        System.out.println(backx.get(bestx)+" "+backy.get(besty));
        System.out.println(best);


    }
}
