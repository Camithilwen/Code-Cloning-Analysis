#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, p[1001], s[1001 * 1001];

int main(){
    while(scanf("%d%d", &N, &M) != EOF && (N|M)){
        for(int x = 0; x < N; x++){
            scanf("%d", p+x);
        }
        p[N++] = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                s[N*x + y] = p[x] + p[y];
            }
        }
        sort(s, s+N*N);
        int ans = 0;
        for(int x = 0; x < N*N; x++){
            int* lb = lower_bound(s, s + N * N, M - s[x]);
            if(lb != s) --lb;
            if(s[x] + *lb > M) continue;
            ans = max(ans, s[x] + *lb);
        }
        printf("%d\n", ans);
    }
    return 0;
}