#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

namespace SCC{
    void visit(const vector<vector<int>>&G,vector<int>&vs,vector<int>&used,int v){
        used[v]=true;
        for(auto u:G[v]){
            if(!used[u])visit(G,vs,used,u);
        }
        vs.push_back(v);
    }

    void visit2(const vector<vector<int>>&T,vector<int>&used,vector<int>&comp,int k,int v){
        comp[v]=k;
        used[v]=true;
        for(auto u:T[v]){
            if(!used[u])visit2(T,used,comp,k,u);
        }
    }

    void decompose(const vector<vector<int>>&G,vector<vector<int>>&H,vector<int>&comp){
        vector<vector<int>>T(G.size());
        for(int i=0;i<G.size();i++){
            for(auto v:G[i]){
                T[v].push_back(i);
            }
        }
        comp.resize(G.size());

        vector<int>vs(G.size());
        vector<int>used(G.size());
        for(int i=0;i<G.size();i++){
            if(!used[i])visit(G,vs,used,i);
        }
        reverse(vs.begin(),vs.end());
        fill(used.begin(),used.end(),0);

        int K=0;
        for(auto v:vs){
            if(!used[v]){
                visit2(T,used,comp,K++,v);
            }
        }

        H.resize(K);
        for(int i=0;i<G.size();i++){
            for(auto v:G[i]){
                H[comp[i]].push_back(comp[v]);
            }
        }
        for(int i=0;i<K;i++){
            sort(H[i].begin(),H[i].end());
            H[i].erase(unique(H[i].begin(),H[i].end()),H[i].end());
        }
    }
}

signed main(){
    int N,M;
    scanf("%lld%lld",&N,&M);
    vector<vector<int>>G(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        G[a].push_back(b);
    }

    vector<vector<int>>H;
    vector<int>comp;

    SCC::decompose(G,H,comp);

    int Q;
    scanf("%lld",&Q);
    while(Q--){
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",(int)(comp[a]==comp[b]));
    }
    return 0;
}