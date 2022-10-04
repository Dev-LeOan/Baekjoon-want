/*
문제
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/

import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int count = 0;
        if (a < 100){    
            System.out.println(a);
        }
        else {
            count = 99;
            for (int j = 111; j <= a; j++){
                count += han(j);
            }
            System.out.println(count);
        }                             
        }
    public static int han(int x){
        int q = x / 100;
        int p = x % 100 /10;
        int y = x % 10;
        if (p*2 == q+y)
            return 1;
        return 0;
        }
    
}
