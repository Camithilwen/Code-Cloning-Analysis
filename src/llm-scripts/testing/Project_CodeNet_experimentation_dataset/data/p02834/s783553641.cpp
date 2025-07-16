#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;


int main() {
    int n, u, v; cin >> n >> u >> v;
    vector<vector<int>> g(n+1);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    vector<int> distU(n+1, -1);
    vector<int> distV(n+1, -1);
    queue<int> qu, qv;
    qu.push(u);
    qv.push(v);
    
    distU.at(u) = 0;
    distV.at(v) = 0;

    while(!qu.empty()){
        int t = qu.front();
        qu.pop();

        for(auto a:g.at(t)){
            if(distU.at(a)!=-1) continue;
            distU.at(a) = distU.at(t) + 1;
            qu.push(a);
        }
    }

    while(!qv.empty()){
        int t = qv.front();
        qv.pop();

        for(auto a:g.at(t)){
            if(distV.at(a)!=-1) continue;
            distV.at(a) = distV.at(t) + 1;
            qv.push(a);
        }
    }

    int fart = v;
    ll dist = 0;
    for(int i=1; i<=n; i++){
        if(distU.at(i)<distV.at(i)){
            if(dist<distV.at(i)){
                dist = distV.at(i);
                fart = i;
            }
        }
    }

    dump(fart);
    if(fart==v){
        cout << 0 << endl;
    }
    else{
        cout << distV.at(fart) - 1 << endl;
    }

    return 0;
}
