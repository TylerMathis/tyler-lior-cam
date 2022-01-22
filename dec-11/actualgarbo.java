import java.util.Scanner;

public class actualgarbo{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();;
		loop: for(int i = 0;i<t;i++){
			long n = scan.nextLong();
			for(int j = 2;j<=5000;j++){
				long upper = n/j+2500;
				for(long k = Math.max(j,upper-5000);k<=upper;k++){
					long sum = ((k * (k + 1) / 2) - ((k - j)*(k-j+1)/2));
					if(sum==n){
						System.out.print(n+" = ");
						for(long l = k-j+1;l<=k;l++){
							if(l<k)
								System.out.print(l+" + ");
							else System.out.println(l);
						}
						continue loop;
					}
				}
			}
			System.out.println("IMPOSSIBLE");
		}
	}

}