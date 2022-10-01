import java.io.*;
import java.io.IOException;
import java.util.StringTokenizer;
public class Main{
	public static void main(String[] args) throws IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int up = Integer.parseInt(st.nextToken());
			int down = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			int day = (L-down) / (up-down);
			if ((L-down) % (up-down) != 0) {
				day++;	 
			}		
			System.out.println(day);
	}
}