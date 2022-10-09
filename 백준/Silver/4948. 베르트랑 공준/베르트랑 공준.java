
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
	public static boolean[] arr;
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while (true) {
			int count = 0;
			int N = Integer.parseInt(br.readLine());
			int two = N * 2; 
			if (N == 0) {
				break;
			}
			arr = new boolean[two + 1];
			arr();
			if (arr[N]== false) {
				count = -1;
			}
			for(int i = N; i <= two; i++) {
				// false = 소수 
				
				if(!arr[i]) {count++;}
				
			}
			System.out.println(count);
		}
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