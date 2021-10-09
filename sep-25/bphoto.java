import java.util.*;

public class bphoto{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n= scan.nextInt();
        Integer[] arr =new Integer[n];
        Integer[] sorted =new Integer[n];
        
        SegmentTree front = new SegmentTree(n+10);
        SegmentTree back = new SegmentTree(n+10);
        HashMap<Integer,Integer> comp = new HashMap<>();
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
            sorted[i] =arr[i];
        }
        Arrays.sort(sorted);
        for(int i = 0;i<n;i++){
            comp.put(sorted[i],i);
        }
        long[] forward =new long[n];
        long[] backward = new long[n];
        front.update(2,4,1);
        long val = front.query(4,4)[0];
        System.out.println(val);
        for(int i =0;i<n;i++){
            System.out.println(comp.get(arr[i]));
            front.update(0, comp.get(arr[i]), 1);
            forward[i] = front.query(comp.get(arr[i]), comp.get(arr[i]))[0];
        }
        for(int i =0;i<n;i++){
            back.update(0, comp.get(arr[i]), 1);
            backward[i] = back.query(comp.get(arr[i]), comp.get(arr[i]))[0];
        }
        int count=0;
        for(int i = 0;i<n;i++){
            System.out.println(forward[i]+" "+backward[i]);
            if(backward[i]*2<forward[i] || forward[i]*2<backward[i]){
                count++;
            }
        }
        System.out.println(count);

    }
    static class SegmentTree{
        long[] sum, max, delta;
        int n;

        public SegmentTree(int n){
            this.n = n;
            sum = new long[n*4+1];
            max = new long[n*4+1];
            delta = new long[n*4+1];
        }

        void prop(int i){
            set(i*2,delta[i]);
            set(i*2+1,delta[i]);
            delta[i] = 0;
        }
        void set(int i, long value){
            delta[i] +=value;
            max[i] += value;
            sum[i]+=value;
        }
        void update(int left, int right, long value){
            update(1,0,n-1,left,right,value);
        }
        void update(int i, int lr, int rr, int left, int right, long value){
            if(lr== left && rr== right){
                set(i,value);
            }
            else{
                prop(i);
                int mid = (lr+rr)/2;
                if(left<=mid){
                    update(i*2,lr,mid,left,Math.min(mid,right),value);
                }
                if(mid<right){
                    update(i*2+1,mid+1,rr,Math.max(mid+1,left),right,value);
                }
                sum[i] = (sum[i*2]+sum[i*2+1]);
                max[i] = Math.max(max[i*2],max[i*2+1]);
                
            }
        }
        long[] query(int left, int right){
            return query(1,0,n-1,left,right);
        }
        long[] query(int i, int lr, int rr, int left, int right){
            if(lr==left && rr==right){
                return new long[]{sum[i],max[i]};
            }
            else{
                prop(i);
                int mid = (lr+rr)/2;
                long[] ret = new long[]{0,Long.MIN_VALUE};
                if(left<=mid){
                    long[] l = query(i*2,lr,mid,left,Math.min(mid,right));
                    ret[0] = (ret[0]+l[0]);
                    ret[1] = Math.max(ret[1],l[1]);
                }
                if(mid<right){
                    long[] r = query(i*2+1,mid+1,rr,Math.max(mid+1,left),right);
                    ret[0] = (ret[0]+r[0]);
                    ret[1] = Math.max(ret[1],r[1]);
                }
                return ret;
            }
        }
    }
}
