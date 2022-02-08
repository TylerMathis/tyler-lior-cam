import java.util.*;
public class jbrute {
    public static void main(String[] args) {
        Scanner scan  =new Scanner(System.in);
        //int t = scan.nextInt();
        for(int k = 1;k<=100;k++){
            int count = 0;
            for(long n = 1;n<1000;n++){
                for(long p = 1;p<1000;p++){
                    boolean isPrime = true;
                    for(int bla = 2;bla<p;bla++){
                        if(p%bla==0)isPrime = false;
                    }
                    if(!isPrime)continue;
                    long val = p;
                    
                    for(long m = 1;m<2000;m++){
                        if(m==1000 && p!=1){
                            //System.out.println(val);
                        }
                        if(n*n-k*val == 1 && p!=1){
                            System.out.println(k+" "+n+" "+p+" "+m);
                            count++;
                        }
                        if(val*p>10000000)break;
                        val*=p;
                    }
                }    

            }
            System.out.println(k+" "+count);
        }
    }
}
