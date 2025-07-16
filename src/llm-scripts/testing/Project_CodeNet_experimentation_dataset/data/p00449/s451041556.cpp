#include <bits/stdc++.h>

using namespace std;

int n,k;

int sssp(int s, int g,vector<vector<int> > ship){
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
  vector<bool> used(n+1,false);

  q.push(make_pair(0,s));
  while(!q.empty()){
    int cost=q.top().first,now=q.top().second; q.pop();
    used[now]=true;
    if(now==g) return cost;

    for(int i=1;i<=n;++i){
      if(ship[now][i]==1000005) continue;
      int ncost=cost+ship[now][i],nexto=i;
      if(used[nexto]==false) q.push(make_pair(ncost,nexto));
    }
  }
  return -1;
}

int main(){
  while(cin >> n >>k && (n || k)){
    vector<vector<int> > ship(n+1,vector<int>(n+1,1000005));
    while(k--){
      int info; cin >> info;
      if(info==0){
	int a,b; cin >> a >> b;
	cout << sssp(a,b,ship) << endl;
      }else{
	int c,d,e; cin >> c >> d >> e;
	ship[c][d]=ship[d][c]=min(ship[c][d],e);
      }
    }
  }
  
  return 0;
}

