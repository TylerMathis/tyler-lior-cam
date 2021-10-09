import java.util.*;
public class a {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] arr =new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
        }
        int left = 0;
        int right = n-1;
        int count = 0;
        while(left<right){
            if(arr[left]==arr[right]){
                left++;
                right--;
                continue;
            }
            count++;
            if(arr[left]<arr[right]){
                arr[left+1]+=arr[left];
                left++;
            }else{
                arr[right-1] += arr[right];
                right--;
            }
        }
        System.out.println(count);
    }
}
