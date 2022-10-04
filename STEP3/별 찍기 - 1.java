/*
문제
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
*/

import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a;
        a = sc.nextInt();
        for(int i = 1; i < a+1; i++){
            for(int k = 0; k < i; k++){
                System.out.print("*");
        }
            System.out.println();
      }  
    }
}
