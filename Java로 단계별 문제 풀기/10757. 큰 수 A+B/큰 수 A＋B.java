import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		BigInteger big1 = new BigInteger(st.nextToken());
		BigInteger big2 = new BigInteger(st.nextToken());
		
		BigInteger sum = big1.add(big2);
		System.out.println(sum);
	}
}
