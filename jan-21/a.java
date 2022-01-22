import java.util.*;
public class a{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        loop:while(t-->0){
            int n = scan.nextInt();
            String[] arr = new String[n];
            String[] arr1=  new String[n];
            for(int i= 0 ;i<n;i++){
                arr[i] = scan.next();
            }
            for(int i= 0 ;i<n;i++){
                arr1[i] = scan.next();
            }
            for(int i = 0;i<n;i++){
                char a = arr[i].charAt(arr[i].length()-1);
                char b = arr1[i].charAt(arr1[i].length()-1);
                if(Math.abs(a-b)<2){
                    if(a=='2' && b=='3' || a=='3' && b=='2'){

                    }else{
                        System.out.println("NO");
                        continue loop;
                    }
                }
            }
            if(arr[n-1].charAt(arr[n-1].length()-1)!='3' && arr[n-1].charAt(arr[n-1].length()-1)!='4'){
                System.out.println("NO");
                continue loop;
            }
            System.out.println("YES");
            
        }
    }
}