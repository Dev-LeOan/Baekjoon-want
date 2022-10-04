/*
문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/

import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
       
    	int C = Integer.parseInt(br.readLine());
    	StringTokenizer st;
    	for (int i = 0; i < C; i++) {
    		st = new StringTokenizer(br.readLine());
    		int N = Integer.parseInt(st.nextToken());
    		int score[] = new int[N];
    		int sum = 0;
    		int avg = 0;
    		for (int j = 0; j < N; j++) {
    			score[j] = Integer.parseInt(st.nextToken());
    			sum += score[j];
    		}
    		avg = sum/N;
    		int K=0;
    		
    		for (int j= 0; j< N ; j++) {
    			if (avg<score[j]) {
    				K++;
    			}
    		}
    		double E = (double) K / N;
    		E = E*100;
    		
    		bw.write(String.format(("%.3f"),E)); bw.write("%"); 
    				
    		bw.newLine();
    	}
    	
    	
    	bw.flush();
    	bw.close();
    	br.close();
    }
}
