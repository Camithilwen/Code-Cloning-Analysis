#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
//#define int ll
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
#define mp make_pair
#define MAX 100000
vector<vector<int>>edge(MAX);
bool visited[MAX];
int prenum[MAX],parent[MAX],lowest[MAX],timer;
int N;
void dfs(int current,int prev){
    prenum[current]=lowest[current]=timer;
    timer++;
    visited[current]=true;
    int  next;
    for(int i=0;i<edge[current].size();i++){
        next=edge[current][i];
        if(!visited[next]){
            parent[next]=current;
            dfs(next,current);
            lowest[current]=min(lowest[current],lowest[next]);
        }else if(next != prev){
            lowest[current] = min(lowest[current],prenum[next]);
        }
    }
}
void art_point(){
    timer=1;
    dfs(0,-1);
    map<int,int>Mp;
    int np=0;
    for(int i=1;i<N;i++){
        int p=parent[i];
        if(p==0)np++;
        else if(prenum[p]<=lowest[i])Mp[p]++;
        if(np>1)Mp[0]++;
    }
        for(auto itr:Mp)
            cout<<itr.first<<endl;
    
}
signed main(){
    int m;
    cin>>N>>m;
    edge.resize(N);
    rep(i,N)visited[i]=false;
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }
    art_point();
}