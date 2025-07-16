#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=998244353;
const int N=2e5+5;



int main(){
    int N, u, v; cin >> N >> u >> v;
    u--, v--;
    vector<vi> G(N);
    for(int i=0; i<N-1; i++){
        int A, B; cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<vi> dist(2, vi(N, -1));
    for(int i=0; i<2; i++){
        queue<int> que;
        que.push(v+(u-v)*i);
        dist[i][v+(u-v)*i]=0;
        while(!que.empty()){
            int p=que.front();
            que.pop();
            for(auto &np : G[p]){
                if(dist[i][np] != -1) continue;
                dist[i][np]=dist[i][p]+1;
                que.push(np);
            }
        }
    }
    int res=0;
    for(int i=0; i<N; i++){
        if(dist[0][i] > dist[1][i]) res=max(res, dist[0][i]);
    }
    res--;
    cout << res << endl;
    return 0;
}