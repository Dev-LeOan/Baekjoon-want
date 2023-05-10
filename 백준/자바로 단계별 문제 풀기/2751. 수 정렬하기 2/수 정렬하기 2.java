import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		ArrayList<Integer> ar = new ArrayList<>();
		for (int i = 0; i < T; i++) {
			int A = Integer.parseInt(br.readLine());
			ar.add(A);
		}
		Collections.sort(ar);
		for (int i : ar) {
			sb.append(i).append('\n');
		}
		System.out.println(sb);
	}
}
