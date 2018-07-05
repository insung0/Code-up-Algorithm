/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;
int N;
char str[1001];

int findA(int x) {
	for(int i = x; i < N; i++) {
		if(str[i] == 'a') return i;
	}

	return -1;
}
int main(int argc, char** argv) {
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++) {

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		scanf("%d", &N);
		scanf("%s", str);

		vector< pair<int, int> > v;
		int nowState = 1;
		int start = -1;

		for(int i = 0; i < N; i++) {
			start = i = findA(i);
			if(i == -1) break;
			nowState = 1;
			for(int j = i+1; j < N; j++) {
				char ch = str[j];
				if(ch == 'e' && nowState == 1) nowState++;
				else if(ch == 'i' && nowState == 2) nowState++;
				else if(ch == 'o' && nowState == 3) nowState++;
				else if(ch == 'u' && nowState == 4) {
					v.push_back(pair<int, int>(start, j));
					break;
				}
			}
		}

		int mini = 100000000;
		pair<int, int> m = pair<int, int>(-2, -2);
		for(int i = 0; i < v.size(); i++) {
			pair<int, int> p = v[i];
			if(p.second - p.first < mini) {
				mini = p.second - p.first;
				m = p;
			}
		}

		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
		printf("%d %d\n", m.first + 1, m.second + 1);

	}

	return 0;//Your program should return 0 on normal termination.
}
