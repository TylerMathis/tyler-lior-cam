import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String[] sorted = new String[n];
        HashMap<String, String> map = new HashMap<>();
        for(int i = 0;i<n;i++){
            char[] s = scan.next().toCharArray();
            StringBuilder sb = new StringBuilder();
            for(int j = 1;j<s.length;j++){
                sb.append(s[j]);
            }
            sb = sb.reverse();
            String one = sb.toString();
            sb = sb.reverse();
            StringBuilder temp = new StringBuilder(""+s[0]);
            sb = temp.append(sb);
            sb = sb.reverse();
            String two = sb.toString();
            sorted[i] = two;
            map.put(two,one);
        }
        Arrays.sort(sorted);
        // for(String curr:sorted){
        //     System.out.println(curr+" "+map.get(curr));
        // }
        int count = 1;
        int max = 0;
        for(int i = 1;i<n;i++){
            if(sorted[i-1].equals(map.get(sorted[i])))count++;
            else if(map.get(sorted[i]).equals(map.get(sorted[i-1])))count++;
            else {
                max = Math.max(count,max);
                count = 1;
            }
        }
        System.out.println(Math.max(max,count));
        
    }
}
