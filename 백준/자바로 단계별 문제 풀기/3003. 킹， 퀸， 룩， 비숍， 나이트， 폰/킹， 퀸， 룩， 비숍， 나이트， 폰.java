import java.util.*;
public class Main{
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int piece;
	int[] chess = {1,1,2,2,2,8};
	int[] check = new int[6];
	for (int i = 0 ; i< chess.length; i++) {
		piece = sc.nextInt();
		if (piece == 0)
			check[i] = chess[i] + piece;
		else
			check[i] = chess[i] - piece;
		System.out.print(check[i] + " ");
	}
	
	}
}

