#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, N, i[1000], j[1000], k[1000], r[1000], h[301];

int main(){
    while(scanf("%d%d%d", &a, &b, &c), a+b+c){
        scanf("%d", &N);
        for(int x = 0; x < N; x++){
            scanf("%d%d%d%d", i+x, j+x, k+x, r+x);
        }
        fill(h, h+301, 2);
        for(int x = 0; x < N; x++){
            if(r[x] == 1){
                h[i[x]] = h[j[x]] = h[k[x]] = 1;
            }
        }
        for(int x = 0; x < N; x++){
            if(r[x]) continue;
            if(h[i[x]]%2 + h[j[x]]%2 + h[k[x]]%2 == 2){
                if(h[i[x]]/2){
                    h[i[x]] = 0;
                }
                if(h[j[x]]/2){
                    h[j[x]] = 0;
                }
                if(h[k[x]]/2){
                    h[k[x]] = 0;
                }
            }
        }
        for(int x = 1; x <= a+b+c; x++){
            printf("%d\n", h[x]);
        }
    }
    return 0;
}