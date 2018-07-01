import java.util.Scanner;

class Main {
	public static void main(String args[]) throws Exception {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] nums = new int[1000001];
		
		for(int i = 0; i <= M; i++){
			nums[i] = i;
		}
		
		nums[1] = 0;
		int sqrt = (int)Math.sqrt(M);
		for(int i = 2; i <= sqrt; i++){
			if(nums[i] == 0) continue;
			for(int j = i + i; j <= M; j += i)
				nums[j] = 0;
		}
		
		for(int i = N; i <= M; i++)
			if(nums[i] != 0)
				System.out.println(nums[i]);
	}
}