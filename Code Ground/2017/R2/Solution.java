/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

import java.util.Scanner;

/*
   As the name of the class should be Solution , using Solution.java as the filename is recommended.
   In any case, you can execute your program by running 'java Solution' command.
 */
class Solution2 {
	static String Answer;

	static int N;
	static String str;
	public static void main(String args[]) throws Exception	{
		/*
		   The method below means that the program will read from input.txt, instead of standard(keyboard) input.
		   To test your program, you may save input data in input.txt file,
		   and call below method to read from the file when using nextInt() method.
		   You may remove the comment symbols(//) in the below statement and use it.
		   But before submission, you must remove the freopen function or rewrite comment symbols(//).
		 */		

		/*
		   Make new scanner from standard input System.in, and read data.
		 */
		Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new FileInputStream("input.txt"));

		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {

			// Answer = 0;
			/////////////////////////////////////////////////////////////////////////////////////////////
			/*
			   Implement your algorithm here.
			   The answer to the case will be stored in variable Answer.
			 */
			/////////////////////////////////////////////////////////////////////////////////////////////

			N = sc.nextInt();
			sc.nextLine();
			str = sc.nextLine();
			if(hanoi(0, 1, 2, N))
				Answer = "Yes";
			else
				Answer = "No";
				
			// Print the answer to standard output(screen).
			System.out.println("Case #"+(test_case+1));
			System.out.println(Answer);
		}
	}
	
	static boolean hanoi(int from, int to, int by, int n){
		while(n > 0){
			if((from+1) % 3 == to){
				if(str.charAt(n-1) == 'A' + from){
					n--;
					int temp = by;
					by = to;
					to = temp;
				}
				else if(str.charAt(n-1) == 'A' + to){
					n--;
					int temp = by;
					by = from;
					from = temp;
				}
				else return false;
			}
			else{
				if(str.charAt(n-1) == 'A' + by){
					n--;
					int temp = from;
					from = to;
					to = temp;
				}
				else{
					n--;
				}
			}
		}
		return true;
	}
}