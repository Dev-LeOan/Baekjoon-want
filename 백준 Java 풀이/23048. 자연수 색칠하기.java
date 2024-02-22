import java.util.Scanner;
//에라토스테네스의 체
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] color = new int[n+1];
        color[1] = 1;

        boolean[] check = new boolean[n+1];
        int count = 1;

        for (long i = 2; i < n+1; i++) { //2부터 서로소이므로
            if(check[(int)i]) continue;
            check[(int)i]=true;
            count++;
            int cl = count;
            color[(int)i] =cl;
            for (long j = i*i; j < n+1; j++) { //에라토스테네스의 체(소수가 아닐 때는 그 약수로 색깔을 칠해야 최소가 될 수 있다.
                if(j%i==0) {
                    check[(int)j] = true; //소수가 아니라면 true 소수이면 그대로 false
                    color[(int)j] = cl;   //
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(count).append("\n");
        for (int i = 1; i < n+1; i++) {
            sb.append(color[i]).append(" ");
        }
        System.out.println(sb);
    }
}