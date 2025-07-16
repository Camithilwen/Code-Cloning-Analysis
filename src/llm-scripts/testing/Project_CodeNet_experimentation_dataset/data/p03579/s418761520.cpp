#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

vector<int> V[110000];
int color[110000];

//二部グラフならtrueを返す
bool dfs(int x,int c){
  color[x]=c;
  for(int i=0;i<V[x].size();i++){
    //隣接している頂点が同じ色ならfalse
    if(color[V[x][i]]==c) return false;
    //隣接している頂点がまだ塗られていないなら-cで塗る
    if(color[V[x][i]]==0 && !dfs(V[x][i],-c)) return false;
  }
  return true;
}


int main(){
    ll N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    if(dfs(0,1)){
        ll count=0;
        for(int i=0;i<N;i++){
            if(color[i]==1) count++;
        }
        cout<<count*(N-count)-M<<endl;
    }else{
        cout<<N*(N-1)/2-M<<endl;
    }
}

