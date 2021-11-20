import java.util.Scanner;

import java.util.*;
public class m {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n=  scan.nextInt();
        int[] arr= new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = scan.nextInt();
        }
        int num = 1000;
        for(int i = 0;i<n;i++){
            num++;
            String s = Integer.toString(num);
            for(int j = 0;j<arr[i];j++){
                s+="0";
            }
            System.out.println(s);
        }
    }
}
