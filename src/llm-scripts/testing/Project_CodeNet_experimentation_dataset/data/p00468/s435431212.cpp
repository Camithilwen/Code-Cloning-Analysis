#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define RE return 0;

#define MAX 505

int n,m;


int main(){
  while(1){
    cin>>n>>m;
    vector<int> G[MAX];
    int num[n+5];
    int used[n+5];
    int ans=0;
    if(n==0&&m==0) break;
    for(int i=0; i<n+5; i++) for(int j=0; j<n+5; j++) {num[i]=INF; used[i]=0;}
    for(int i=0; i<m; i++){
      int a,b;
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    
    queue<int> que;
    que.push(1);
    num[1]=0;
    used[1]=true;
    while(!que.empty()){
      int v=que.front(); que.pop();
      for(int i=0; i<G[v].size(); i++){
        int e=G[v][i];
        if(used[e]) continue;
        num[e]=num[v]+1;
        used[e]=true;
        que.push(e);
      }
    }
    
    for(int i=1; i<=n; i++){
      if(num[i]<=2) {
        ans++;
      }
    }
    
    cout<<ans-1<<en
  }
}
