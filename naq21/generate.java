import java.util.*;
public class generate {
    public static void main(String[] args) {
        loop:for(int i = 0;i<1000;i++){
            int a = (int)(Math.random()*100000);
            //a = 605;
            int[][] freq = new int[10][3];
            String aa = Integer.toString(a);
            for(int j = 0;j<aa.length();j++){
                freq[aa.charAt(j)-'0'][0]++;
            }
            for(int diff = 1;diff<=a;diff++){
                int one = a-diff;
                int two = a+diff;
                //System.out.println(one+" "+two);
                String s = Integer.toString(one);
                String s1 = Integer.toString(two);
                for(int j = 0;j<10;j++){
                    freq[j][1] = 0;
                    freq[j][2] = 0;
                }
                for(int j = 0;j<s.length();j++){
                    freq[s.charAt(j)-'0'][1]++;
                }
                for(int j = 0;j<s1.length();j++){
                    freq[s1.charAt(j)-'0'][2]++;
                }
                boolean uno = false;
                for(int j = 0;j<10;j++){
                    if(freq[j][1]>0 && freq[j][0]>0){
                        uno = true;
                    }
                }
                boolean dos = false;
                for(int j = 0;j<10;j++){
                    if(freq[j][2]>0 && freq[j][0]>0){
                        dos=  true;
                    }
                }
                if((!dos && uno) || (!uno && dos))continue loop;
                if(!dos && !uno){
                    System.out.println(a+" "+one+" "+two);
                    break;
                }
                
            }
        }
    }
}
