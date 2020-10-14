package Exercises;

public class Fibonacci {

	public static void main(String[] args) {
	int n = 40;
		
System.out.println("| The fib of " + n + " is: " + fib(n) + " |\n");
System.out.println("------------------------");
System.out.println("| END ITERATIVE FIB     |");
System.out.println("------------------------");

System.out.println("------------------------");
System.out.println("| INSIDE RECURSIVE FIB |");
System.out.println("------------------------\n"); 
System.out.println("| The fib of " + n + " is: " + fibRecur(n) + " |\n");
System.out.println("------------------------");
System.out.println("| END RECURSIVE FIB     |");
System.out.println("------------------------");
	}
	
	private static int fib(int n) {
		System.out.println("------------------------");
		System.out.println("| INSIDE ITERATIVE FIB |");
		System.out.println("------------------------\n");
		int a = 0;
		int b = 1;
		int c;
	
		if(n == 0) {
			return a;
		}
	
		for(var i = 2; i <= n; ++i) {
			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
	
	private static int fibRecur(int n) {

		if(n <= 1) {
			return n;
		}
		return fibRecur(n - 1) + fibRecur(n - 2);
	}

}
