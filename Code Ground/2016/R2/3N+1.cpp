#include<stdio.h>
#include<algorithm>

using namespace std;

#define ull unsigned long long

ull back(ull n, int k, bool isMin){
	if(!k) return n;
	
	ull res = back(2*n, k-1, isMin);
	
	if(((n-1) >= 6) && (((n-1) % 3)== 0) && (( ((n-1)/3)%2) == 1 )){
		if(isMin)
			res = max(res, back((n-1)/3, k-1, isMin));
		else
			res = min(res, back((n-1)/3, k-1, isMin));
	}
	
	return res;
}

int main(){
	int T;
	setbuf(stdout, NULL);
	
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		int k;
		scanf("%d", &k);
		
		printf("Case #%d\n%llu %llu\n", i, back(1, k, 0), back(1, k, 1));
	}
}
