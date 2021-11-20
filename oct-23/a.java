import java.util.*;
public class a{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        thing[] arr =new thing[n];
        int[] ori = new int[n];
        for(int i = 0;i<n;i++){
            String s = scan.next();

            ori[i] = scan.nextInt();
            double r = ori[i];
            
            if(s.charAt(1)=='u')r = rad(r);
            if(s.charAt(1)=='y')r*=2;
            //System.out.println(r);
            arr[i] = new thing(s,r,ori[i]);
        }
        Arrays.sort(arr);
        boolean good = true;
        for(int i = 0;i<n-1;i++){
            if(arr[i+1].s.charAt(1)=='y' && arr[i].s.charAt(1)=='u'){
                if(arr[i+1].ori*2<arr[i].ori)good = false;
            }else if(arr[i+1].s.charAt(1)=='u' && arr[i].s.charAt(1)=='y'){
                if(arr[i+1].ori<arr[i].ori*2)good = false;
            }
        }
        if(!good){
            System.out.println("impossible");
            return;
        }
        for(thing curr:arr){
            System.out.println(curr.s+" "+curr.ori);
        }
    }
    static double rad(double s){
        return Math.sqrt(2*(s*1.0/2)*(s*1.0/2))*2;
    }
    static class thing implements Comparable<thing>{
        String s;
        double r;
        int ori;
        public thing(String s, double r, int ori){
            this.s = s;
            this.r = r;
            this.ori = ori;
        }
        public int compareTo(thing o){
            return Double.compare(this.r,o.r);
        }
    }
}