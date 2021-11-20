import java.util.*;

public class h {
    static int[] arr;
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n=  scan.nextInt();
        arr =new int[n];
        for(int i =0 ;i<n;i++){
            arr[i]= scan.nextInt();
        }
        Arrays.sort(arr);
        int[] next = new int[60*60*60];
        int[] prev = new int[60*60*60];
        int max = 60*60*60;
        TreeSet<Integer> valids = new TreeSet<>();
        for(int i = 0;i<60;i++){
            String s1 = Integer.toString(i);
            for(int j =0 ;j<60;j++){
                String s2 = Integer.toString(j);
                for(int k=  0;k<60;k++){
                    String s3 = Integer.toString(k);
                    int time = i*3600+j*60+k;
                    //System.out.println(s1+" "+s2+" "+s3);
                    if(!weGood(s3) || !weGood(s2) || !weGood(s1))continue;
                    valids.add(time);
                }
            }
        }
        //System.out.println(valids.size());
        for(int i = 0;i<60*60*60;i++){
            if(valids.lower(i)!=null){
                prev[i] = valids.lower(i);
            }else if(valids.higher(i)!=null){
                prev[i]=  valids.higher(i);
            }
            if(valids.higher(i)!=null){
                next[i] = valids.higher(i);
            }else if(valids.lower(i)!=null){
                next[i] = valids.lower(i);
            }
        }

        int q = scan.nextInt();
        for(int i= 0;i<q;i++){
            int a = scan.nextInt();
            String s = scan.next();
            
            int time = time(s);
            if(valids.contains(time)){
                String out = out(time);
                System.out.println(i+" "+out);
                continue;
            }
            int ne = next[time];
            int diffAhead = 0, diffBefore = 0;
            if(ne<time){
                diffAhead = max-time;
                diffAhead+=ne;
            }else{
                diffAhead = Math.abs(ne-time);
            }
            int be = prev[time];
            if(be>time){
                diffBefore = max-be;
                diffBefore+=time;
            }else{
                diffBefore = Math.abs(be-time);
            }
            int timeOut = 0;
            if(diffAhead==diffBefore){
                if(ne<be){
                    timeOut = ne;
                }else timeOut = be;
            }
            if(diffAhead<diffBefore)timeOut = ne;
            else if(diffBefore<diffAhead)timeOut = be;
            String out = out(timeOut);
            System.out.println(i+" "+out);
        }
    }
    static String out(int in){
        int hours = in/3600;
        in%=3600;
        int mins = in/60;
        in%=60;
        int sec = in;
        String res = "";
        String h = Integer.toString(hours);
        String m = Integer.toString(mins);
        String s = Integer.toString(sec);
        if(hours<10){
            h = "0"+h;
        }
        if(mins<10){
            m = "0"+m;
        }
        if(sec<10){
            s = "0"+s;
        }
        res = h+":"+m+":"+s;
        return res;
    }
    static boolean weGood(String in){
        if(in.length()<=1 && arr[0]==0)return false;
        for(int i = 0;i<arr.length;i++){

            if(in.contains((char)(arr[i]+'0')+""))return false;
        }
        return true;
    }
    static int time(String in){
        int res = 0;
        String[] arrs = in.split(":");
        int hours = Integer.parseInt(arrs[0]);
        int min = Integer.parseInt(arrs[1]);
        int sec = Integer.parseInt(arrs[2]);
        res+=hours*3600+min*60+sec;
        return res;
    }
}
