#include <iostream>
using namespace std;
 
bool v[10];
int tmp[10];
 
void dfs(int num, int d, int n) {
    tmp[d] = num;
 
    if (d == n) {
        for (int i = 1; i <= n; i++) { cout << tmp[i] << " "; } cout << '\n'; return;
    }
 
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        v[i] = true;
        dfs(i, d + 1, n);
        v[i] = false;
    }
}
 
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        v[i] = true;
        dfs(i, 1, n);
        v[i] = false;
    }
    return 0;
}

