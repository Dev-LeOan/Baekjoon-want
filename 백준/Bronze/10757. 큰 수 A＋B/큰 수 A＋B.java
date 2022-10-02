import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger big1 = sc.nextBigInteger(); 
		BigInteger big2 = sc.nextBigInteger(); 
		sc.close();
		
		BigInteger sum = big1.add(big2);
		System.out.println(sum);
	}
}