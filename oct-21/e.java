import java.util.Scanner;
import java.io.PrintWriter;
import java.util.*;
public class e{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n =  scan.nextInt();
        PrintWriter out = new PrintWriter(System.out);
        int[] arr= new int[n];
        int[] pos = new int[n+1];
        TreeSet<Integer> set =new TreeSet<>();
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
            pos[arr[i]] = i;
        }
        for(int i = 0;i<n;i++){
            set.add(arr[i]);
            if(set.lower(arr[i])!=null){
                out.println(set.lower(arr[i]));
            }else{
                out.println(-1);
            }
        }
        out.flush();
        out.close();
    }
}