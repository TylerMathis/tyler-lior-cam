import java.util.*;
public class j {
    public static void main(String[] args) {
        Scanner scan  =new Scanner(System.in);
        int t = scan.nextInt();
        HashSet<Integer> set =new HashSet<>();
        int start = 3;
        int gap = 5;
        while(start<=1e9+1){
            set.add(start);
            start+=gap;
            gap+=2;
        }
        int max = 2_000_001;
        boolean[] isPrime = new boolean[max+1];
        Arrays.fill(isPrime,true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 4;i<=max;i+=2){
            isPrime[i]=  false;
        }
        for(int i = 3;i*i<=max;i+=2){
            if(isPrime[i]){
                for(int j =i*i;j<max;j+=i*2){
                    isPrime[j] = false;       
                }
            }
        }
        HashSet<Long> primes = new HashSet<>();
        for(int i = 2;i<max;i++){
            if(isPrime[i]){
                primes.add((long)i);
            }
        }
        
        //for(int k = 999_999_900;k<=1_000_000_000;k++){
        while(t-->0){
            int k = scan.nextInt();
            int count = 0;
            if(set.contains(k)){
                System.out.println(-1);
                continue;
            }
            for(Long prime:primes){
                long curr = prime;
                long starte = prime;
                for(int m = 1;m<100;m++){
                    
                    if((long)(1e18)/k < curr)break;
                    long squaredd = 1+curr*k;
                    boolean good = false;
                    long cringe = (long)(Math.floor(Math.sqrt(squaredd)));
                    if(cringe*cringe == squaredd)good = true;
                    if(good){
                        count++;
                    }
                    if(((long)(1e18)/starte) < curr)break;
                    curr *= starte;
                }
            }
            //System.out.println(k+" "+count);
            System.out.println(count);
        }
    }
}
