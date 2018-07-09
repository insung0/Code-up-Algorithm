#include <stdio.h>
#include <algorithm>

using namespace std;
int N;

class array{
public:
	int index;
	int v;
	
	bool operator <(array &a){
		return this->v < a.v;
	}
};

array arr[200001];

int main(void)
{
	int T, test_case;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);
		
		for(int i = 0; i < N; i++){
			arr[i].index = i;
			scanf("%d", &arr[i].v);
		}
		
        sort(arr, arr+ N);
        
        int cnt = 0;
        int maxI = -1, minI = 2000000000;
        for(int i = 0, j = N - 1; i <= j; i++, j--){
        	if(i == arr[i].index && arr[i].index > maxI) {
				cnt++;
			}
        	if(i != j && j == arr[j].index && minI > arr[j].index) {
        		cnt++;
			}
        	maxI = max(maxI, arr[i].index);
        	minI = min(minI, arr[j].index);
		}
        
		printf("Case #%d\n", test_case+1);
	    printf("%d\n", cnt);
        
	}

	return 0;
}
