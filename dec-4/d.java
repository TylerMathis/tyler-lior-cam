import java.io.*;
import java.util.*;
public class d {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        ArrayList<String> s = new ArrayList<>();
        HashMap<String, Integer> freqCor = new HashMap<>();
        HashMap<String, Integer> freqinCor = new HashMap<>();
        
        for(int i = 0;i<n;i++){
            s.add(scan.next());
        }
        HashMap<String, String> trans = new HashMap<>();
        int t = scan.nextInt();
        boolean bad = false;
        for(int i = 0 ;i<t;i++){
            String a = scan.next();
            String b = scan.next();
            trans.put(a,b);
            String c = scan.next();
            if (c.charAt(0)=='c'){
                freqCor.put(a,freqCor.getOrDefault(a, 0)+1);
            }else{
                bad = true;
                freqinCor.put(a,freqinCor.getOrDefault(a, 0)+1);
            }
        }
        long correct = 1;
        long incorrect = 1;
        for(int i = 0;i<n;i++){
            int powerCor = freqCor.getOrDefault(s.get(i), 0);
            correct*=(long)(powerCor);
            int powerInc = freqinCor.getOrDefault(s.get(i), 0);
            incorrect*=(long)(Math.max(1,powerInc+powerCor));
        }
        //System.out.println(bad+" "+correct+" "+incorrect);
        if(incorrect==1){
            for(int i = 0;i<n;i++){
                System.out.print(trans.get(s.get(i))+" ");
            }
            System.out.println();
            if(!bad)
                System.out.println("correct");
            else{
                System.out.println("incorrect");
            }
        }
        else{
            System.out.println(correct+" correct");
            if(!bad){
                System.out.println(0+ " incorrect");
            }else
                System.out.println(incorrect - correct+" incorrect");
        }
    }
}
