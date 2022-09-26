# Baekjoon-want
This is a auto push repository for Baekjoon Online Judge created with [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub).
#백준
### 주사위 세개
```Java
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,b,c;
        int top;
        a = sc.nextInt(); b = sc.nextInt(); c = sc.nextInt();
        if (a > b && a > c){
            top = a;
        }
        else if (b>a && b>c){
            top = b;
        }
        else
            top = c;
        if (a == b && b == c){
            System.out.println(10000+a*1000);
        }
        else if ((a==b && b!=c) || (b==c && b!=a)){
            System.out.println(1000+ b * 100);
        }
        else if (a==c && b!=a){
            System.out.println(1000+ a * 100);
        }
        else if ( a!=b && b!=c && c!=a){
            System.out.println(top*100);
        }
        
 
    }
}
