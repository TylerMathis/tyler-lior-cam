public class kbrute {
    public static void main(String[] args) {
        int n= 10;

        for(int i = 0;i<n;i++){
            int start = n-i;
            if(i%2==1){
                System.out.print("  ");
            }
            for(int j = 0;j<start;j++){
                System.out.print("  ");
            }
            int end = n+i;
            for(int j = 0;j<n+i*2;j++){
                System.out.print("o ");
            }for(int j = 0;j<start;j++){
                System.out.print("  ");
            }
            System.out.println();
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n*3;j++){
                System.out.print("o ");
            }
            System.out.println();
        }
        System.out.println();
        for(int i = 0;i<n;i++){
            int start = i;
            if(i%2==1){
                System.out.print("  ");
            }
            for(int j = 0;j<start;j++){
                System.out.print("  ");
            }
            int end = n+i;
            for(int j = 0;j<3*n-i*2;j++){
                System.out.print("o ");
            }for(int j = 0;j<start;j++){
                System.out.print("  ");
            }
            System.out.println();
        }

    }
}
