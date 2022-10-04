import java.io.*;
import java.io.IOException;
public class Main{
	public static void main(String[] args) throws IOException{
		int[][] a = new int[15][15]; //[k][n]
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int k = 0; k < 15; k++) {
			a[k][1] = 1;
			a[0][k] = k;
		}
		for (int k = 1 ;k <15; k++) {
			for (int n = 2; n<15;n++) {
				a[k][n] = a[k][n-1] + a[k-1][n] ;
			}
		}
		for (int i =0; i<T;i++) {
			int K = Integer.parseInt(br.readLine());
			int N = Integer.parseInt(br.readLine());
			System.out.println(a[K][N]);
		}
	
	}
}
