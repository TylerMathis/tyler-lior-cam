import java.util.*;
public class b{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n=  scan.nextInt();
        Person[] arr =new Person[n];
        for(int i = 0;i<n;i++){
            arr[i] = new Person(scan.next(),scan.nextDouble(),scan.nextDouble());
        }
        Arrays.sort(arr);
        double best = 534953;
        double ans = 0;
        ArrayList<String> names = new ArrayList<>();
        for(int i = 0;i<n;i++){
            ans+=arr[i].first;
            int count = 0;
            for(int j = 0;j<4;j++){
                if(i==j)continue;
                if(count==3)break;
                count++;
                ans+=arr[j].second;
            }
            if(ans<best){
                names.clear();
                names.add(arr[i].name);
                count = 0;
                for(int j = 0;j<4;j++){
                    if(i==j)continue;
                    if(count==3)break;
                    count++;
                    names.add(arr[j].name);
                }
            }
            best = Math.min(best,ans);
            ans = 0;
        }
        System.out.println(best);
        for(String sol:names){
            System.out.println(sol);
        }
    }
    static class Person implements Comparable<Person>{
        String name;
        double first, second;
        public Person(String a, double first, double second){
            this.first = first;
            this.second = second;
            this.name = a;
        }
        @Override
        public int compareTo(Person o){
            return Double.compare(this.second, o.second);
        }
    }
}