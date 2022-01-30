import java.util.Scanner;

public class a{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int sum = 0;
        for(int i = 0;i<6;i++){
            sum+=scan.nextInt()*5;
        }
        System.out.println(sum);
    }
}