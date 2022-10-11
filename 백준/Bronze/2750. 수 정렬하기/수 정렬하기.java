import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int[] arr = new int[T];
		int tmp;
		for (int i = 0; i<T; i++) {
			int N = Integer.parseInt(br.readLine());
			arr[i] = N;
		}
		for (int i = 0; i<T; i++) {
			for (int j = i+1; j<T; j++) {
				if (arr[j] < arr[i]) {
					tmp = arr[j];
					arr[j] = arr[i];
					arr[i] = tmp;
				}
			}
		}
		for (int i = 0; i<T; i++) {
			System.out.println(arr[i]);
		}
	}
}