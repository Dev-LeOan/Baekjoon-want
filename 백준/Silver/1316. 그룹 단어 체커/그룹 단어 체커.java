import java.util.*;
public class Main{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int count = 0;
		int x = sc.nextInt();
		for(int i=0; i<x;i++) {
			if(check() == true) {
				count++;
			}
		}
		System.out.println(count);
	}	
	
	
	public static boolean check() {
		
		boolean[] check = new boolean[26];
		int Find = 0;
		String y = sc.next();
		
		for (int i = 0; i < y.length(); i++) {
			
			int l = y.charAt(i);
			
			
			if ( Find != l ) {
				if(check[l - 'a']== false){
					check[l - 'a'] = true;
					Find = l;
				}
			
				else {
					return false;
				}
			}
		
		
			else {
				continue;
			}
		}
		return true;
	}
}