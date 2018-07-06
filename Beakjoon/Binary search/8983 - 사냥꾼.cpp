#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, L;
int guns[100001];
pair<int, int> animals[100001];

int main(){
	
	scanf("%d%d%d", &M, &N, &L);
	
	for(int i = 0; i < M; i++){
		scanf("%d", &guns[i]);
	}
	
	for(int i = 0; i < N; i++){
		scanf("%d%d", &animals[i].first, &animals[i].second);
	}
	
	sort(guns, guns + M);
	
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(L < animals[i].second) continue;
		int left = animals[i].first - (L - animals[i].second);
		int right = animals[i].first + (L - animals[i].second);
		
		int low = 0, high = M - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			if(left <= guns[mid] && guns[mid] <= right){
				cnt++;
				break;
			}
			else if(left > guns[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	
	printf("%d", cnt);
	return 0;
}
