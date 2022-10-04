import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int count = 0;
		char[] arr = s.toCharArray();
		count = 0;
		for(int i=0; i<arr.length;i++) {
			if(arr[i] == 'c' ) {
				if (i+1 != arr.length) {
					if (arr[i+1] == '=') {
						i++;
					}	
					else if (arr[i+1] == '-') {
						i++;
					}
				}
			}
			else if(arr[i] == 'd') {
				if (i+1 != arr.length) {
					if (arr[i+1] == 'z') {
						if (i+2 != arr.length) {
							if (arr[i+2] == '=') {
								i += 2;
								}
							}
						}
					else if (arr[i+1] == '-') {
						i++;
						}
					}
				}
			else if(arr[i] == 'l') {
				if (i+1 != arr.length) {
					if (arr[i+1] == 'j') {
						i++;
					}
				}
			}	
			
			else if(arr[i] == 'n') {
				if (i+1 != arr.length) {
					if (arr[i+1] == 'j') {
						i++;
					}
				}
			}
			
			else if(arr[i] == 's') {
				if (i+1 != arr.length) {
					if (arr[i+1] == '=') {
						i++;
					}
				}
			}
			else if(arr[i] == 'z') {
				if (i+1 != arr.length) {
					if (arr[i+1] == '=') {
						i++;
					}
				}
			}
			count++;
		}
		System.out.println(count);
	}
}