#include <stdio.h>

int map[51][51];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
int w,h;
void DFS(int x, int y){
    int i, nx, ny;
 	map[x][y] = 0;
    for(i = 0; i < 8; i++){
        nx = x + dx[i];
        ny = y + dy[i];
 
        if(nx >= h || nx < 0 || ny >= w || ny < 0){
            continue;
        }
 
        if(map[nx][ny]){
            DFS(nx,ny);
        }
    }
 
}
    
 
 
int main(){
 
    while(1){
        scanf("%d%d", &w, &h);
        if(!w && !h){
            return 0;
        }
 
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        
 		int cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j]){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n",cnt);
 
    }
 
    return 0;
}

