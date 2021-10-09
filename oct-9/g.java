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
        // for(int i = 0;i<n;i++){
        //     System.out.println(i+" "+sizes[i]);
        // }
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
            // for(int j = 0;j<n;j++){
            //     System.out.println("j "+j+" "+sizes[j])2
            // }
            //System.out.println(bestid);
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
        //System.out.println(sizes[0]);
        if(k==1 && n>=3){
            System.out.println("NO");
            return;
        }
        if(sizes[0]-1<=k){
            System.out.println("YES");
            return;
        }
        System.out.println("NO");

    }   
    static void delete(int idx,int start){
        sizes[idx] = 1;
        for(Integer to:adj[idx]){
            if(distance[to]>distance[idx]){
                //System.out.println(to+" "+sizes[to]);
                sizes[idx] = Math.max(sizes[idx],1+sizes[to]);
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
    static int size(int idx,int par){
        if(adj[idx].size()==1)return sizes[idx] = 1;
        int sum = 1;
        for(Integer to:adj[idx]){
            if(to==par)continue;
            distance[to] = distance[idx]+1;
            sum=Math.max(sum,1 + size(to,idx));
        }
        return sizes[idx] = sum;
    }
}
