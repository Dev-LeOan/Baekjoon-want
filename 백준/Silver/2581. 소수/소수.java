import java.util.StringTokenizer;
import java.io.IOException;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(br.readLine());
		int b = Integer.parseInt(br.readLine());
		int[] arr = new int[b];
		int sum = 0;
		int k = 0;
		
		for (int i = 0; i<b; i++) {
			arr[i] = 0;
		}
		for(int x = a ; x<=b; x++) {
			boolean chk = false;
			chk = check(x);
			if (chk) {
				arr[k] = x;
				k++;
				sum += x;
			}
		}
		int min = arr[0];
		for (int y = 0; y<b; y++) {
			if (arr[y] != 0 && arr[y]<min) {
				min = arr[y];
			}
		}
		
		if (arr[0] != 0) {
			System.out.println(sum);
			System.out.println(min);
		}
		else {
			System.out.println(-1);
		}
		
	}
	public static boolean check(int x) {
		if (x == 0) {
			return false;
		}
		if (x == 1) {
			return false;
		}
		if (x == 2) {
			return true;
		}
		for (int i = 2; i<x; i++) {
			if (x%i == 0) {
				return false; //소수가 아니면 false
			}	
		}
		return true; //소수면 true
	}
}