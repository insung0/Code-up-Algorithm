#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        // pre: �������� ����, suc: �������� ���
        int N, K, W, time[1000], pre[1000] = {0};
        vector<int> suc[1000];
        scanf("%d %d", &N, &K);
        for(int i=0; i<N; i++)
            scanf("%d", time+i);
        for(int i=0; i<K; i++){
            int X, Y;
            scanf("%d %d", &X, &Y);
            suc[X-1].push_back(Y-1);
            pre[Y-1]++;
        }
        scanf("%d", &W);
        W--;
 
        // result: �ش� �ǹ��� ���� �����ϴ� �� �ɸ��� �ּ� �ð�
        int result[1000] = {0};
        queue<int> Q;
        // �����ڰ� �ϳ��� ���� ������ ���� ť�� push
        for(int i=0; i<N; i++)
            if(!pre[i]) Q.push(i);
 
        // W�� �ǹ��� �����ڰ� �ϳ��� ���� ������(�� ���ŵ� ������ ����)
        while(pre[W] > 0){
            int u = Q.front();
            Q.pop();
            // ��� ������ �ǹ��� �ּ� �Ǽ����۽ð��� ����
            for(int next: suc[u]){
                result[next] = max(result[next], result[u]+time[u]);
                if(--pre[next] == 0) Q.push(next);
            }
        }
        // ��ǥ �ǹ��� ���� �� �ɸ��� �ð��� ���ؾ� ��
        printf("%d\n", result[W]+time[W]);
    }
}


