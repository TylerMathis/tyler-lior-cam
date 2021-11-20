public class brute {
    public static void main(String[] args) {
        for(int i = 1;i<10000;i++){
            double sum = Math.sqrt(3*i*i);
            //System.out.println(sum);
            if(Math.round(sum)==sum){
                System.out.println(i);
            }
        }
    }
}
