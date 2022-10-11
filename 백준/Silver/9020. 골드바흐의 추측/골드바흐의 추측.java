import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
	public static boolean[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		arr = new boolean[10001];
		arr();  //false는 소수
		for (int i = 0; i<T; i++) {
			int N = Integer.parseInt(br.readLine());
			for (int j = N/2; j > 0; j--) { 
				if (arr[j] != true && arr[N-j] != true ) {
					System.out.printf("%d %d",j,N-j);
					System.out.println();
					break;
				}
				
			}
		}
		
	}
	public static void arr() { 
		arr[0] = arr[1] = true;
		for(int i = 2; i <= Math.sqrt(arr.length); i++) {
			if(arr[i]) continue;
			for(int j = i * i; j < arr.length; j += i) {
				arr[j] = true;
			}
		}
	}
}