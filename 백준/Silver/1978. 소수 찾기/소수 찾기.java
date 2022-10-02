import java.util.StringTokenizer;
import java.io.IOException;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		int count = 0;
		int check = 1;
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			
		while(st.hasMoreTokens()) {
		
			int a= Integer.parseInt(st.nextToken());
		
			if ( a == 1) {
				continue;
			}
			if (a == 2) {
				count++;
				continue;
			}
			for (int j=2;j<a;j++) {
				if (a%j != 0) {
					check = 1;
				}
				else {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				count++;
			}
			
		}
		System.out.println(count);
	}
}