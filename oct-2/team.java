import java.util.*;

public class team{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();
        int[] arr= new int[n];
        int[] sec = new int[m];
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
        }
        for(int i = 0;i<m;i++){
            sec[i] = scan.nextInt();
        }
        Arrays.sort(arr);
        Arrays.sort(sec);
        int[] beat = new int[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i]>sec[j])beat[i]++;
            }
        }
        int ans = 0;
        for(int i = n-1;i>=2;i--){
            for(int j = i-1;j>=1;j--){
                for(int l = j-1;l>=0;l--){
                    int one = beat[i]-2;
                    int two = beat[j]-1;
                    int three = beat[l];
                    if(one<=0 || two<=0 || three<=0)continue;
                    System.out.println("ans pre "+ans);
                    ans+=(beat[i]-2)*(beat[j]-1)*(beat[l]);
                    System.out.println(one);
                    System.out.println(two);
                    System.out.println(three);
                }
            }
        }
        System.out.println(ans);
    }
}