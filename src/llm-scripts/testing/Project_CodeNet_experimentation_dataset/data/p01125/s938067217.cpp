#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    int tr[21][21];
    while(true){
        scanf("%d", &N);
        if(N == 0) break;
        for(int i = 0; i <= 20; i++){
            fill(tr[i], tr[i] + 21, 0);
        }
        for(int i = 0; i < N; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            tr[x][y] = 1;
        }
        scanf("%d", &M);
        int cnt = 0;
        int rx = 10, ry = 10;
        for(int i = 0; i < M; i++){
            char d; int s;
            scanf(" %c%d", &d, &s);
            int dx, dy;
            if(d == 'N'){
                dx = 0, dy = 1;
            }else if(d == 'E'){
                dx = 1, dy = 0;
            }else if(d == 'S'){
                dx = 0, dy = -1;
            }else{
                dx = -1, dy = 0;
            }
            while(s--){
                rx += dx;
                ry += dy;
                if(tr[rx][ry] == 1){
                    tr[rx][ry] = 0;
                    cnt += 1;
                }
            }
        }
        if(cnt == N){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}