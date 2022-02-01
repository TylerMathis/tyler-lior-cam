import java.util.*;
public class a{
    static HashSet<Integer> seen;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String ss = scan.next();
        char[] s = ss.toCharArray();
        int n = s.length;
        if(n==1 && s[0]=='1'){
            System.out.println("0 2");
            return;
        }
        seen = new HashSet<>();
        for(int i = 0;i<n;i++){
            seen.add(s[i]-'0');
        }
        //go small
        StringBuilder sb = new StringBuilder();
        StringBuilder large = new StringBuilder();

        int value = s[0]-'0';
        int flip = 0;
        loop:for(int i = 0;i<10;i++){
            if(!seen.contains(value)){
                //System.out.println(value+" "+flip);
                if(flip == 0){
                    sb.append(value);
                    sb = go(sb,n-1,0);
                }else{
                    sb.append(value);
                    sb = go(sb,n-2,0);
                }
                break loop;
            }
            value--;
            if(value<=0) {
                value = 9;
                flip = 1;
            }
        }
        value = s[0]-'0';
        flip = 0;
        loop:for(int i = 0;i<10;i++){
            if(!seen.contains(value)){
                if(flip == 0){
                    large.append(value);
                    large = go(large,n-1,1);
                }else{
                    large.append(value);
                    large = go(large,n,1);
                }
                break loop;
            }
            value++;
            if(value>9) {
                value = 1;
                flip = 1;
            }
        }
        //System.out.println(sb+" "+large);
        // loop:for(int i = s[0]-'0';i>=0;i--){
        //     if(!seen.contains(i)){
        //         sb.append(i);
        //         loopy:for(int k = 0;k<n-1;k++){
        //             for(int j = 9;j>=0;j--){
        //                 if(!seen.contains(j)){
        //                     sb.append(j);
        //                     continue loopy;
        //                 }
        //             }
        //         }
        //         break loop;
        //     }
        // }
        // loop:for(int i = s[0]-'0';i<=9;i++){
        //     if(!seen.contains(i)){
        //         large.append(i);
        //         loopy:for(int k = 0;k<n-1;k++){
        //             for(int j = 0;j<=9;j++){
        //                 if(!seen.contains(j)){
        //                     large.append(j);
        //                     continue loopy;
        //                 }
        //             }
        //         }
        //         break loop;
        //     }
        // })
        if(sb.length() == 0 && large.length() == 0){
            if(!seen.contains(0)){
                System.out.println(0);
            }else
            System.out.println("Impossible");
        }
        else if(sb.length()==0){
            System.out.println(large);
        }
        else if(large.length()==0){
            System.out.println(sb);
        }else{
            long a = Long.parseLong(sb.toString());
            long b = Long.parseLong(large.toString());
            long in = Long.parseLong(ss);
            if(Math.abs(in-a) == Math.abs(in-b) && a!=b){
                if(a<b){
                    System.out.println(a+" "+b);
                }else{
                    System.out.println(b+" "+a);
                }
            }else if(Math.abs(in-a)<Math.abs(in-b)){
                System.out.println(a);
            }else{
                System.out.println(b);
            }
        }

    }
    static StringBuilder go(StringBuilder sb, int limit, int pattern){
        if(pattern==0){
            loopy:for(int k = 0;k<limit;k++){
                for(int j = 9;j>=0;j--){
                    if(!seen.contains(j)){
                        sb.append(j);
                        continue loopy;
                    }
                }
            }
        }else{
            loopy:for(int k = 0;k<limit;k++){
                for(int j = 0;j<=9;j++){
                    if(!seen.contains(j)){
                        sb.append(j);
                        continue loopy;
                    }
                }
            }
        }
        return sb;
    }
}