#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<ll> used(100010), tp;
vector<vector<ll>> G(100010);
/*
void dfs(ll v){
    if(used[v]) return;
    used[v] = 1;
    for(auto& u:G[v]){
        dfs(u);
    }
    tp.push_back(v);
}*/

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> rc(N),deg(N);
    ll a,b;
    rep(i,N-1+M){
        cin >> a >> b;
        a--;b--;
        rc[b]++;
        G[a].push_back(b); 
        deg[b]++;
    }
    ll root;
    rep(i,N){
        if(rc[i] == 0){
            root = i;
            break;
        }
    }
    queue<ll> que;
    vector<ll> par(N,-1);
    que.push(root);
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto& u:G[v]){
            deg[u]--;
            if(deg[u] == 0){
                par[u] = v;
                que.push(u);
            }
        }
    }
    rep(i,N){
        cout << par[i]+1 << endl;
    }
    /*dfs(root);
    vector<ll> v(N);
    rep(i,N){
        v[tp[i]] = i;
    }
    //PR(v,N);
    vector<ll> ans(N,-1);
    rep(i,N){
        for(auto& u:G[i]){
            if(v[i] > v[u]){
                //cout << u+ << endl;
                ans[i] = u;
                break;
            }
        }
    }
    rep(i,N){
        cout << ans[i]+1 << endl;
    }
    /*queue<ll> que;
    que.push(root);
    prev[root] = -1;
    used[root] = 1;*/
    /*
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto& u:G[v]){
            if(used[u] != 0){
                G[prev[u]].erase(lower_bound(G[prev[u]].begin(),G[prev[u]].end(),u));
                prev[u] = v;
                que.push(u);
                continue;
            }
            used[u] = 1;
            prev[u] = v;
            que.push(u);
        }
    }*/
    /*rep(i,N){
        cout << prev[i]+1 << endl;
    }*/
}