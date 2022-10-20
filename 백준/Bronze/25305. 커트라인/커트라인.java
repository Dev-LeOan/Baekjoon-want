import java.io.*;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
import java.util.StringTokenizer;
public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st1.nextToken());
		int k = Integer.parseInt(st1.nextToken());
		ArrayList ar = new ArrayList();
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for (int i = 0; i<N; i++) {
			int A = Integer.parseInt(st2.nextToken());
			ar.add(A);
		}
		br.close();
		Collections.sort(ar);
		System.out.println(ar.get(N-k));
	}
}