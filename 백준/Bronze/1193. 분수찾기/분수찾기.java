import java.io.*;
import java.io.IOException;
public class Main{
	public static void main(String[] args) throws IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int a = Integer.parseInt(br.readLine());
			int prev_sum = 0;
			int current_can = 1;
			while(true) {
				if (a <= prev_sum + current_can) {
					if (current_can % 2 == 1) { //정방향
						System.out.println((current_can - (a-prev_sum-1)+ "/" + (a-prev_sum)));
					    break;
                    }
					else { //역방향
						System.out.println((a-prev_sum + "/" + (current_can - (a-prev_sum-1))));
					    break;    
                    }
				}
				else 
				{
					prev_sum += current_can;
					current_can++;
				}
			}
			
	}
}