#include<stdio.h>
#include<algorithm>
#include<queue>

int N, M;

using namespace std;

struct vertex{
	int num;
	bool complete;
	vector<int> edges;
};

vertex graph[32001];
int main(){
	
	scanf("%d%d", &N, &M);
	
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].edges.push_back(b);
		graph[b].num++;
	}
	
	queue<int> q;
	for(int i = 1; i <= N; i++){
			if(!graph[i].num){
				q.push(i);
			}
	}
			
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i : graph[x].edges){
			graph[i].num--;
			if(!graph[i].num)
				q.push(i);
		}
	}
	
	return 0;
}

