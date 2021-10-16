import java.util.*;
import java.io.*;
public class c{
    public static void main(String[] args) throws IOException{
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        HashSet<Integer> left= new HashSet<>();
        HashSet<Integer> right= new HashSet<>();
        String[] line1 = scan.readLine().split(" ");
        String[] line2 = scan.readLine().split(" ");
        int n = Integer.parseInt(line1[0]);
        int  k =  Integer.parseInt(line1[1]);
        for(int i = 0;i<n;i++){
            int at =  Integer.parseInt(line2[i]);
            int need = k-at;
            if(left.contains(need)){
                if(right.contains(need)){
                    System.out.println("no");
                    return;
                }
                right.add(at);
            }else{
                left.add(at);
            }
        }
        System.out.println("yes");
    }
}