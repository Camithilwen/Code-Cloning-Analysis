//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

#ifdef __APPLE__
    # include <iostream>
    # include <cmath>
    # include <algorithm>
    # include <stdio.h>
    # include <cstdint>
    # include <cstring>
    # include <string>
    # include <cstdlib>
    # include <vector>
    # include <bitset>
    # include <map>
    # include <queue>
    # include <ctime>
    # include <stack>
    # include <set>
    # include <list>
    # include <random>
    # include <deque>
    # include <functional>
    # include <iomanip>
    # include <sstream>
    # include <fstream>
    # include <complex>
    # include <numeric>
    # include <immintrin.h>
    # include <cassert>
    # include <array>
    # include <tuple>
    # include <unordered_map>
    # include <unordered_set>
    # include <thread>
#else
    # include <bits/stdc++.h>
#endif

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

#define arr (int)(1e6+10)

bool use[arr];
vi reb_one[arr];
vector<pii> reb[arr];
vi rem_comps[arr];
int comps=0;

int dist_bfs[arr];
vi reb_bfs[arr];

void add_bfs_edge(int u,int v)
{
//    cout<<"bfs_edge :: "<<u<<" "<<v<<"\n";
    reb_bfs[u].pb(v);
    reb_bfs[v].pb(u);
}

void dfs(int now)
{
    use[now]=1;
    rem_comps[now].pb(comps);
    for (auto wh:reb_one[now]){
        if (!use[wh]){
            dfs(wh);
        }
    }
}

void process(int v)
{
    dfs(v);
    comps++;
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        reb[w].pb(mp(u,v));
    }
    for (int i=0;i<arr;i++){
        for (auto j:reb[i]){
            reb_one[j.fir].pb(j.sec);
            reb_one[j.sec].pb(j.fir);
        }

        for (auto j:reb[i]){
            if (!use[j.fir]) {
                process(j.fir);
            }
            if (!use[j.sec]) {
                process(j.sec);
            }
        }

        for (auto j:reb[i]){
            reb_one[j.fir].clear();
            reb_one[j.sec].clear();
            use[j.fir]=0;
            use[j.sec]=0;
        }
    }

//    for (int i=1;i<=n;i++){
//        cout<<"rem_comps["<<i<<"] :: ";
//        for (auto j:rem_comps[i]){
//            cout<<j<<" ";
//        }
//        cout<<"\n";
//    }

    for (int i=1;i<=n;i++){
        int fake = comps++;
        for (auto j:rem_comps[i]){
            add_bfs_edge(fake,j);
        }
    }

    queue<int> q;
    for (int i=0;i<comps;i++){
        dist_bfs[i]=inf;
    }
    for (auto j:rem_comps[1]){
        dist_bfs[j]=0;
        q.push(j);
    }
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb_bfs[now]){
            if (dist_bfs[wh]>dist_bfs[now]+1){
                dist_bfs[wh]=dist_bfs[now]+1;
                q.push(wh);
            }
        }
    }
    int ans=inf;
    for (auto j:rem_comps[n]){
        ans=min(ans,dist_bfs[j]);
    }
    cout<<(ans==inf?-1:ans/2 + 1)<<"\n";
}
