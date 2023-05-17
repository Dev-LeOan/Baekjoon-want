import java.io.*;
import java.io.IOException;
public class Main{
	public static void main(String[] args) throws IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int a = Integer.parseInt(br.readLine());
			int n = 1;
			int b = 2;
			if ( a == 1) {
				System.out.println(1);
			}
			else {
				while (b<=a) {
					b = b + (6 * n);
					n++;
				}
				System.out.println(n);
			}
	}
}
