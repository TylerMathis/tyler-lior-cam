import java.util.*;
public class k{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] to = new int[n*2];
        int[] in = new int[n*2];
        for(int i = 0;i<2*n;i++){
            to[i] = scan.nextInt()-1;
            in[to[i]]++;
        }
        ArrayDeque<Integer> deq1 = new ArrayDeque<>();
        //ArrayDeque<Integer> deq2 = new ArrayDeque<>();
        int[] dist = new int[2*n];
        boolean[] v = new boolean[2*n];
        HashSet<Integer> S = new HashSet<>();
        for(int i = 0;i<2*n;i++){
            if(in[i]==0){
                
                deq1.add(i);
                v[i] = true;
                S.add(i);
            }
        }
        int par = 0;
        while(true){
            par++;
            while(!deq1.isEmpty()){
                int curr = deq1.poll();
                int going = to[curr];
                if(v[going])continue;
                v[going] = true;
                deq2.add(going);
                if(par%2==0)S.add(going);
            }
            if(deq2.isEmpty())break;
            for(Integer curr:deq2){
                deq1.add(curr);
            }
            deq2.clear();
        }
        for(int i= 0;i<2*n;i++){
            if(!v[i]){
                ArrayDeque<Integer> deq= new ArrayDeque<>();
                v[i] = true;
                deq.add(i);
                while(!deq.isEmpty()){
                    int curr = deq.poll();
                    int going = to[curr];
                    if(v[going])continue;
                    v[going] = true;
                    if(!S.contains(curr)){
                        S.add(going);
                    }
                }
            }
        }
        for(Integer curr:S){
            System.out.print((curr+1)+" ");
        }
        System.out.println();
    }
}