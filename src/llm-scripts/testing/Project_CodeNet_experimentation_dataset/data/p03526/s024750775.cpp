#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define INF 10000000000000000

LL zab[11000];

int main(){
    LL n;
    cin >> n;
    vector<pair<LL,LL> > g;
    for(LL i = 0; i < n; i++){
        LL a, b;
        cin >> a >> b;
        a += b;
        g.push_back(make_pair(a,b));
    }
    sort(g.begin(), g.end());

    for(LL i = 0; i <= n; i++){
        zab[i] = INF;
    }
    zab[0] = 0;

    for(LL i = 0; i < n; i++){
        g[i].first -= g[i].second;
        for(LL j = n-1; j >= 0; j--){
            if(zab[j] <= g[i].first){
                zab[j+1] = min(zab[j+1], zab[j] + g[i].second);
            }
        }
    }

    LL best = 0;
    for(LL i = 0; i <= n; i++){
        if(zab[i] < INF){
            best = i;
        }
    }
    cout << best << endl;
}
