import java.util.Scanner;

public class b{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double[] arr = new double[10];
        double sTd = 0;
        double sum = 0;
        for(int i = 0;i<10;i++){
            arr[i] = scan.nextDouble();
            sum+=arr[i];
        }
        sum/=10;
        double sum2 = 0;
        for(int i = 0;i<10;i++){
            sum2+=(arr[i]-sum)*(arr[i]-sum);
        }
        sum2/=(9);
        sum2 = Math.sqrt(sum2);
        //System.out.println(sum2);
        System.out.println(sum2-1e-10<=1.0 ? "COMFY" : "NOT COMFY");
    }
}