import java.util.*;
public class c{
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int timee = scan.nextInt();
        int n= scan.nextInt();
        Integer[] arr= new Integer[n];
        for(int i = 0;i<n;i++){
            arr[i]= scan.nextInt();
        }
        Arrays.sort(arr);
        int time = 0;
        int count = 0;
        for(Integer curr:arr){
            time+=curr;
            if(time>timee){
                break;
            }
            count++;
        }
        System.out.println(count);
    }
}