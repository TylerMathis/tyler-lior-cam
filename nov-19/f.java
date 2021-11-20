import java.util.*;
public class f{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        HashMap<Integer, Integer> th = new HashMap<>();
        HashMap<Integer, Integer> cut = new HashMap<>();
        
        Integer[] ah = new Integer[n];
        Integer[] cu = new Integer[n];
        pet[] in = new pet[n];
        for(int i = 0;i<n;i++){
            ah[i] = scan.nextInt();
            cu[i] = scan.nextInt();
            in[i] = new pet(ah[i],cu[i]);
        }
        Arrays.sort(ah);
        Arrays.sort(cu);
        for(int i = 0;i<n;i++){
            th.put(ah[i],i);
            cut.put(cu[i],i);
        }
        //we need to check if a bigger number exists
        for(pet curr:in){
            curr.think = th.get(curr.think);
            curr.cute = cut.get(curr.cute);
        }
        TreeSet<Integer> set =new TreeSet<>();
        Arrays.sort(in);
        for(pet curr:in){
            set.add(curr.think);
            if(set.lower(curr.think)!=null){
                System.out.println("yes");
                return;
            }
        }
        System.out.println("no");
        
    }
    static class pet implements Comparable<pet>{
        int think, cute;
        public pet(int think, int cute){
            this.think = think;
            this.cute = cute;
        }
        @Override
        public int compareTo(pet o){
            return o.cute-cute;
        }
    }
}