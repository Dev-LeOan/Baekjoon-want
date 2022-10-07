import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
 
public class Main {
	public static boolean[] arr;
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		arr = new boolean[N + 1];
		arr();
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = M; i <= N; i++) {
			// false = 소수 
			if(!arr[i]) sb.append(i).append('\n');
		}
		System.out.println(sb);
	}
 
	public static void arr() {
		// true = 소수아님 , false = 소수 
		arr[0] = arr[1] = true;
		
		for(int i = 2; i <= Math.sqrt(arr.length); i++) {
			if(arr[i]) continue;
			for(int j = i * i; j < arr.length; j += i) {
				arr[j] = true;
			}
		}
	}
}