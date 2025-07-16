//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
#pragma unused(INF,PI,LINF)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

vector<vector<ii>> graph;

vector<int> dist;
void dijkstra(int s){
    dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        ii front=pq.top();pq.pop();
        int d=front.first,u=front.second;
        if(d==dist[u]){
            for(auto p:graph[u]){
                int v=p.first,w=p.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
#ifdef local_test
    //    input
    //    freopen("input","w",stdout);
    //    cout<<"1 \n 100 10 \n";
     freopen("input","r",stdin);
     freopen("output","w",stdout);
#endif
    int n,m;
    cin>>n>>m;
    int r;
    cin>>r;
    graph=vector<vector<ii>>(n, vector<ii>());
    dist=vi(n,INF);
    F(i,0,m){
        int s,t,d;
        cin>>s>>t>>d;
        graph[s].pb(mp(t,d));
//        graph[t].pb(mp(s,d));
    }
    dijkstra(r);
    for(int d:dist) if(d<INF) cout<<d<<"\n"; else cout<<"INF\n";
}