import java.util.*;
public class a {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t= scan.nextInt();
        loop:while(t-->0){
            int n = scan.nextInt();
            
            ppl[] arr =new ppl[n];
            int max = 0;
            int sumB = 0;
            for(int i = 0;i<n;i++){
                arr[i]= new ppl(scan.nextInt(),scan.nextInt());
                sumB+=arr[i].b;
            }
            if(n==2){
                System.out.println("Yes");
                continue;
            }
            Arrays.sort(arr);
            for(int i = 1;i<n;i++){
                int val = arr[i].a+sumB-arr[i].b;
                for(int j =0;j<i;j++){
                    if(val>arr[j].a){
                        System.out.println("No");
                        continue loop;
                    }
                }
                
            }
            //     for(int j = i+1;j<n;j++){
            //         if(arr[i].a+val>=arr[i].a){
            //             System.out.println("NO");
            //             continue loop;
            //         }
            //     }
            // }
            System.out.println("Yes");
        }
    }
    static class ppl implements Comparable<ppl>{
        int a, b;
        public ppl(int a ,int b){
            this.a = a;
            this.b = b;
        }
        @Override
        public int compareTo(ppl o){
            if(o.a==a){
                return b-o.b;
            }
            return (o.a)-(a);
            //return (o.a-o.b)-(a-b);
        }
    }
}