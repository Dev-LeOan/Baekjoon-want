import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String s = sc.next();
		char[] arr = s.toCharArray();
		int count =0;
		for (int i =0; i<arr.length; i++) {
			if(arr[i] >= 'A' && arr[i] <='C') {
				count +=3; 
			}
			else if(arr[i] >= 'D' && arr[i] <='F') {
				count +=4; 
			}
			else if(arr[i] >= 'G' && arr[i] <='I') {
				count +=5; 
			}
			else if(arr[i] >= 'J' && arr[i] <='L') {
				count +=6; 
			}
			else if(arr[i] >= 'M' && arr[i] <='O') {
				count +=7; 
			}
			else if(arr[i] >= 'P' && arr[i] <='S') {
				count +=8; 
			}
			else if(arr[i] >= 'T' && arr[i] <='V') {
				count +=9; 
			}
			else {
				count +=10; 
			}
		}
		System.out.println(count);
	}
}