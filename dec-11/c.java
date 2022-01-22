import java.util.Scanner;

public class c {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		loop: for (int i = 0; i < t; i++) {
			int n = scan.nextInt();
			int start = 0;
			int size = 0;
			for (int j = 2; j * j / 2 < n + 10; j++) {
				if (j % 2 == 0) {
					if ((n % j) == j/2) {
						start = n / j;
						size = j;
						break;
					}
				} else {
					if (n % j == 0) {
						start = n / j;
						size = j;
						break;
					}
				}
			}
			//System.out.println(start+" "+size);
			if(start==0){
				System.out.println("IMPOSSIBLE");
				continue;
			}
			loopy: for (int l = Math.max(1,start - 10 - size/2); l < start-size/2+10; l++) {
				long sum = 0;
				for (int k = l; k < l + size; k++) {
					if (k <= 0)
						continue loopy;
					sum += k;
				}
				if (sum == n) {
					System.out.print(n + " = ");
					for (int k = l; k < l + size; k++) {
						if (k < l + size-1)
							System.out.print(k + " + ");
						else
							System.out.println(k);
					}
					continue loop;
				}
			}
			if(start==0){
				System.out.println("IMPOSSIBLE");
				continue;
			}
			
		}
	}

}