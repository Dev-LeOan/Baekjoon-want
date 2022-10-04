import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int a = Integer.parseInt(br.readLine());
        for(int b = 0; b < a; b++){
        	String[] i =br.readLine().split(" ");
        	int q = Integer.parseInt(i[0]);
        	int w = Integer.parseInt(i[1]);
            bw.write(Integer.toString(q+w)+ '\n');
        }
        bw.flush();    
    }
}
