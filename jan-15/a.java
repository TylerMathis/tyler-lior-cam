import java.util.*;
public class a {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int n = scan.nextInt();
        ArrayList<Integer>[] arr =new ArrayList[n];
        int height = (int)(Math.log(n)/Math.log(2))+1;
        int[] sizes = new int[height];
        for(int i = 0;i<height;i++){
            sizes[i] = (int)(Math.pow(2,i));
        }
        for(int i = 0;i<n;i++){
            arr[i] = new ArrayList<>(sizes[i]);
        }
        int idx = 0;
        while(idx<b){
            ArrayDeque<Integer> deq = new ArrayDeque<>();
        }

    }
}
