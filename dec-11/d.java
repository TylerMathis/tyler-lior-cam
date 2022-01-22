import java.util.*;
public class d {
    static double[] x, y, r;
    static ArrayList<Integer>[] con;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t-- > 0){
            int n = scan.nextInt();
            x = new double[n];
            y = new double[n];
            r = new double[n];
            con = new ArrayList[n];
            for(int i = 0;i<n;i++){
                con[i] = new ArrayList<Integer>();
                x[i] = scan.nextDouble();
                y[i] = scan.nextDouble();
                r[i] = scan.nextDouble();
            }
            for(int i = 0;i<n;i++){
                for(int j =i+1 ;j<n;j++){
                    merge(i,j);
                }
            }
            boolean[] v =new boolean[n];
            long[] num = new long[n];
            long[] den = new long[n];
            int[] dir = new int[n];
            num[0] = 1;
            den[0] = 1;
            
            ArrayDeque<Integer> deq = new ArrayDeque<>();
            deq.add(0);
            v[0] = true;
            while(!deq.isEmpty()){
                int curr = deq.poll();
                //System.out.println(curr);
                for(Integer to:con[curr]){
                    //SHOULD NEVER HAPPEN
                    if(v[to])continue;
                    v[to] = true;
                    dir[to] = dir[curr]^1;
                    num[to] = num[curr]*(long)(r[curr]);
                    den[to] = den[curr]*(long)(r[to]);
                    double gcd = gcd(num[to],den[to]);
                    num[to]/=gcd;
                    den[to]/=gcd;
                    deq.add(to);
                }
            }
            for(int i =0 ;i<n;i++){
                if(num[i] == 0){
                    System.out.println("not moving");
                    continue;
                }
                if(den[i]==1){
                    System.out.print(num[i]+" ");
                }else{
                    System.out.print(num[i]+"/"+den[i]+" ");
                }
                System.out.println(dir[i]==0?"clockwise":"counterclockwise");
            }
        }
    }
    static void merge(int a, int b){
        double dist = Math.sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
        double sum = r[a]+r[b];
        if(dist+1e-9>sum && dist-1e-9<sum){
            con[a].add(b);
            con[b].add(a);
        }
    }
    static long gcd(long a, long b){
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
    
}
