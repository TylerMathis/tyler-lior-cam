import java.util.ArrayDeque;
import java.util.*;
import java.util.Scanner;

public class i {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n];
        HashMap<String, Integer> map = new HashMap<>();
        String[] names = new String[n];
        for(int i = 0;i<n;i++){
            String s = scan.next();
            adj[i] = new ArrayList<Integer>();
            names[i] = s;
            map.put(s,i);
        }
        for(int i = 0;i<n;i++){
            String thr = scan.next();
            int num = scan.nextInt();
            scan.nextLine();
            for(int j = 0;j<num;j++){
                String s = scan.nextLine();
                String[] arr = s.split(" ");
                for(int k=  0;k<arr.length;k++){
                    if(arr[k].equals("import"))continue;
                    String act = arr[k];
                    if(arr[k].contains(","))act = arr[k].substring(0,arr[k].length()-1);
                    adj[i].add(map.get(act));
                }
            }
        }
        int smol = Integer.MAX_VALUE;
        String name = "";
        ArrayList<String> namesOut = new ArrayList<>();
        for(int i = 0;i<n;i++){
            int[] v = new int[n];
            int[] from = new int[n];
            int base = 100000;
            Arrays.fill(v,base);
            v[i] = 0;
            ArrayDeque<Integer> deq= new ArrayDeque<>();
            deq.add(i);

            loop:while(!deq.isEmpty()){
                int curr = deq.poll();
                for(Integer to:adj[curr]){
                    if(to==i){
                        v[to] = v[curr]+1;
                        from[to] = curr;
                        break loop;
                    }else{
                        if(v[to]!=base)continue;
                        from[to] = curr;
                        v[to] = v[curr]+1;
                        deq.add(to);
                    }
                }
            }
            if(v[i]!=0){
                if(v[i]<smol){
                    namesOut.clear();
                    int star = i;
                    while(from[star]!=i){
                        namesOut.add(names[star]);
                        star = from[star];
                    }
                    namesOut.add(names[star]);
                    smol = v[i];
                }
            }
        }
        if(smol==Integer.MAX_VALUE){
            System.out.println("SHIP IT");
        }else{
            Collections.reverse(namesOut);
            for(int i = 0;i<namesOut.size();i++){
                if(i==namesOut.size()-1){
                    System.out.println(namesOut.get(i));
                }else{
                    System.out.print(namesOut.get(i)+" ");
                }
            }
            
        }
    }
}
