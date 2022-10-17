import java.io.*;
import java.io.IOException;

public class Main{
	public static void main(String[] args) throws IOException {
		int[] arr = new int[10001];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i<T; i++) {
			arr	[Integer.parseInt(br.readLine())]++;
		}
		br.close();
		StringBuilder sb = new  StringBuilder();
		for(int i = 1; i < 10001; i++){
			while(arr[i] > 0){
				sb.append(i).append('\n');
				arr[i]--;
				}
			}
		System.out.println(sb);
	}
}