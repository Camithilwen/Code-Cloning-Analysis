#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
#define ps push_back
double pi = 3.141592653589793;
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
//ここから始めよう
int p[214514],q[214514],c[214151];
vector<P> G[614514];
int lastid=0;
map<P,int> sid;
int getid(int v,int c){
    P p(v,c);
    if(sid.find(p)!=sid.end())return sid[p];
    return sid[p]=lastid++;
}
void addedge(int p,int q,int c){
    int v=getid(p,c);int u=getid(q,c);
    G[v].ps(P(u,0));
    G[u].ps(P(v,0));
}
signed main(){
    int n,m;cin>>n>>m;
    rep(i,0,m){
        cin>>p[i]>>q[i]>>c[i];
        p[i]--;q[i]--;
        addedge(p[i],q[i],c[i]);
    }
    rep(i,0,m){
        G[getid(p[i],c[i])].ps(P(lastid+p[i],1));
        G[getid(q[i],c[i])].ps(P(lastid+q[i],1));
        G[lastid+p[i]].ps(P(getid(p[i],c[i]),1));
        G[lastid+q[i]].ps(P(getid(q[i],c[i]),1));
    }
    vector<int> d(lastid+n,mod);d[lastid]=0;
    priority_queue<P> que;
    que.push(P(0,lastid));
    while(!que.empty()){
        auto p=que.top();que.pop();
        int u=p.second,dist=-p.first;
        if(dist>d[u])continue;
        for(auto e:G[u]){
            int v=e.first,c=e.second;
            if(d[v]>d[u]+c){
                d[v]=d[u]+c;
                que.push(P(-d[v],v));
            }
        }
    }int ans=d[lastid+n-1];
    if(ans==mod)ans=-1;
    else ans/=2;
    cout<<ans<<endl;return 0;
}