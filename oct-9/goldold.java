import java.util.*;
public class g {
    static ArrayList<Integer>[] adj;
    static int[] sizes;
    static int[] distance;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k = scan.nextInt();
        adj = new ArrayList[n];
        for(int i =0 ;i<n;i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0;i<n-1;i++){
            int one = scan.nextInt()-1;
            int two = scan.nextInt()-1;
            adj[one].add(two);
            adj[two].add(one);
        }
        //find the sizes of every subtree
        sizes = new int[n];
        distance = new int[n];
        distance[0] = 0;
        int sendIT = size(0,-1);
        //idea is delete the node with biggest depth at least a distance i
        //from the root at every move
        for(int i = 0;i<n;i++){
            sizes[i] = adj[i].size()-1;
            System.out.println(i+" "+sizes[i]);
        }
        for(int i = 0;i<k;i++){
            //find the biggest depth that's at least a distance i away
            int max = -1;
            int dist = -1;
            int bestid  = -1;
            for(int j = 0;j<n;j++){
                if(distance[j]<=i)continue;
                if(sizes[j]>=max){
                    if(sizes[j]==max){
                        if(distance[j]<dist){
                            dist = distance[j];
                            bestid = j;
                        }
                    }else{
                        dist = distance[j];
                        max = sizes[j];
                        bestid = j;
                    }
                }
                
            }
            //delete the node at bestid
            //update the depths of every parent
            for(int j = 0;j<n;j++){
                System.out.println("j "+j+" "+sizes[j]);
            }
            System.out.println(bestid);
            sizes[bestid] = 0;
            int par = 0;
            for(Integer to:adj[bestid]){
                if(distance[to]<distance[bestid]){
                    par = to;
                    break;
                }
            }
            delete(par,bestid);
        }
        if(sizes[0]<k){
            System.out.println("YES");
            return;
        }
        System.out.println("NO");

    }   
    static void delete(int idx,int start){
        sizes[idx] = 1;
        for(Integer to:adj[idx]){
            if(distance[to]>distance[idx]){
                sizes[idx] = Math.max(sizes[idx],sizes[to]);
            }
        }
        for(Integer to:adj[idx]){
            if(distance[to]<distance[idx]){
                delete(to,start);
                break;
            }
        }
        
        deleteDown(start);
    }
    static void deleteDown(int idx){
        for(Integer to:adj[idx]){
            if(distance[to]>=distance[idx]){
                sizes[to] = 0;
                deleteDown(to);
            }
        }
    }
}
