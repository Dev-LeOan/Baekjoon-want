/*
문제
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
시험 성적을 출력한다.
*/

import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a;
        a = sc.nextInt();
        if (a<=100 && a>=90)
            System.out.println("A");
        else if (a<90 && a>=80)
            System.out.println("B");
        else if (a<80 && a>=70)
            System.out.println("C");
        else if (a<70 && a>=60)
            System.out.println("D");
        else 
            System.out.println("F");
    }
}
