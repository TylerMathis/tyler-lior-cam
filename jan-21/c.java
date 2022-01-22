import java.util.*;
public class c {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        outer:while(t-->0){
            int n=  10;
            int[] freq = new int[n];
            int numbers = 0;
            for(int i = 0;i<n;i++){
                freq[i] = scan.nextInt();
                numbers+=freq[i];
            }
            //before we place a number, check if any other number's frequency becomes greater than the rest of the numbers
            StringBuilder sb = new StringBuilder();
            int last = -1;
            int left = numbers;

            if(freq[0] == numbers){
                System.out.println(numbers == 1?0:-1);
                continue;
            }
            loopy:for(int i = 0;i<numbers;i++){
                for(int j = i==0?1:0;j<10;j++){
                    if(freq[j]>left-freq[j]){
                        if(last == j){
                            System.out.println(-1);
                            continue outer;
                        }
                        //place j
                        freq[j]--;
                        sb.append(j);
                        last = j;
                        left--;
                        continue loopy;
                    }
                }
                for(int j = i==0?1:0 ;j<10;j++){
                    if(j== last)continue;
                    if(freq[j]>0){
                        //we'd want to place this one
                        freq[j]--;
                        sb.append(j);
                        last = j;
                        left--;
                        continue loopy;
                    }
                }
                //System.out.println(-1);
                //continue outer;
            }
            System.out.println(sb);
            
        }
    }
}
