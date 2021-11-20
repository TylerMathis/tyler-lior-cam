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
        int one = 0;
        int two = 0;
        for(int i = 0;i<m+c;i++){
            if(!compressx.containsKey(x[i])){
                compressx.put(x[i],one);
                backx.put(one,x[i]);
                one++;
            }
            if(!compressy.containsKey(y[i])){
                compressy.put(y[i],two);
                backy.put(two,y[i]);
                two++;
            }
        }
        for(int i = 0;i<m;i++){
            x1[i] = compressx.get(x1[i]);
            y1[i] = compressy.get(y1[i]);
        }
        for(int i = 0;i<c;i++){
            cx1[i] = compressx.get(cx1[i]);
            cy1[i] = compressy.get(cy1[i]);
        }


        int[] freqx = new int[one];
        int[] freqy = new int[two];
        for(int i = 0;i<m;i++){
            freqx[x1[i]]++;
            freqy[y1[i]]++;
        }
        
        ArrayList<obj> list =new ArrayList<>();
        for(int i = 0;i<c;i++){
            if((freqx[cx1[i]] == 1 || freqy[cy1[i]] == 1) && (freqx[cx1[i]] <2 || freqy[cy1[i]] <2)){
                list.add(new obj(cx1[i],cy1[i]));
                
            }
        }
        int[][] freq =new int[one][two];
        for(obj curr:list){

            for(int i = 0;i<two;i++){
                freq[curr.x][i]++;
            }
            for(int i = 0;i<one;i++){
                freq[i][two]++;
            }
            freq[curr.x][curr.y]--;
        
        }
        int best = 0;
        int bestx = 0;
        int besty = 0;
        for(int i = 0;i<one;i++){
            for(int j = 0;j<two;j++){
                System.out.print(freq[i][j]+" ");
                int sum = freq[i][j];
                if(sum>best){
                    bestx = i;
                    besty = j;
                    best = sum;
                }
            }
            System.out.println();
        }
        System.out.println(backx.get(bestx)+" "+backy.get(besty));
        System.out.println(best);


    }
    static class obj{
        int x, y;
        public obj(int x1, int y1){
            x = x1;
            y = y1;
        }
    }
}
