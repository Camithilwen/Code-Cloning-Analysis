#include<bits/stdc++.h>
#define REP(i,n) for(long long i=0;i<n;++i)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
using namespace std;
using point = pair< int,int >;
using ll = long long;

int main(){
    int n;
    int c;
    int graph[11];
    while (~scanf("%d", &n)) {
        if (!n) break;
        fill(graph, graph + 11, 0);
        REP(i, n) {
            scanf("%d", &c);
            graph[c]++;
        }
        FOR(i, 0, 10) {
            if (!graph[i]) printf("-\n");
            else {
                REP(j, graph[i]) printf("*");
                puts("");
            }
        }
    }
    return 0;
}


