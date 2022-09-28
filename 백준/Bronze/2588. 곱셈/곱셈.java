import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,b;
        a = sc.nextInt();
        b = sc.nextInt();
        int A = b%10; //385 % 10 = 5;
        int B = b%100 - A;  // 385 % 100 = 85 - 5 = 80
        int C = b - (A+B); // 385 - 85 = 300
        
        System.out.println(a * A);  // 5 * 472
        System.out.println((a * B)/10); // 80 * 472 / 10
        System.out.println((a * C)/100);  //300 * 472 / 100
        System.out.println(a*b);
    }

}
