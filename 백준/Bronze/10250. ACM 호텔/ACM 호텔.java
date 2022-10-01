import java.io.*;
import java.io.IOException;
import java.util.StringTokenizer;
public class Main{
	public static void main(String[] args) throws IOException{
			//T 반복할 횟수 H 층수 W 방 개수 N 번째 손님
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());	
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i<T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int H = Integer.parseInt(st.nextToken());	
			int W = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			if (N%H == 0) {
				count1 = H * 100;
				count2 = N / H;
			}
			else {
				count1 = N%H*100;
				count2 = N/H+1;
			}
			System.out.println (count1 + count2);
		}
	}
}