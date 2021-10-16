import java.util.*;

public class k {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[] left =new int[3];
        int[] reset = new int[3];
        int[] s = new int[3];
        int b = scan.nextInt();
        int n = scan.nextInt();
        int e = scan.nextInt();
        left[0] = b;
        left[1] = n;
        left[2] = e;
        for(int i =0 ;i<3;i++){
            reset[i] = left[i];
            s[i] = scan.nextInt();
        }
        long lo = 1;
        long hi = Integer.MAX_VALUE;
        int kayaks = (b+n+e)/2;
    
        Long[] kay = new Long[kayaks];
        for(int i = 0;i<kayaks;i++){
            kay[i] = scan.nextLong();
        }
        Arrays.sort(kay);
        long ans = Integer.MIN_VALUE;
        outer:while(lo<=hi){
            for(int i = 0;i<3;i++){
                left[i] = reset[i];
            }
            long mid = (lo+hi)/2;
            //System.out.println(lo+" "+hi+" "+mid);
            loop:for(int i= 0;i<kayaks;i++){
                long min = Integer.MAX_VALUE;
                int idx1 = 0;
                int idx2 = 0;
                for(int j= 0;j<3;j++){
                    for(int k = 0 ;k<3;k++){
                        if(j==k){
                            if(left[j]>=2){
                                long speed = kay[i]*(s[j]+s[k]);
                                if(speed>=mid){
                                    if(speed<min){
                                        idx1 = j;
                                        idx2 = k;
                                        min = speed;
                                    }
                                }
                            }
                        }else{
                            if(left[j]>=1 && left[k]>=1){
                                long speed = kay[i]*(s[j]+s[k]);
                                if(speed>=mid){
                                    if(speed<min){
                                        idx1 = j;
                                        idx2 = k;
                                        min = speed;
                                    }
                                }
                            }
                        }
                    }
                }
                left[idx1]--;
                left[idx2]--;
                //System.out.println(i+" "+min);
                if(min==Integer.MAX_VALUE){
                    //we failed
                    hi = mid-1;
                    continue outer;
                }
            }
            
            ans = Math.max(ans,mid);
            lo = mid+1;
        }
        System.out.println(ans);
    }
}
