#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
#define OFFSET 200000



vector< vector<int> > pl_d(400001);
vector< vector<int> > pl_r(400001);
vector< vector<int> > pl_u(400001);
vector< vector<int> > pl_l(400001);
vector< vector<int> > df_u(400001);
vector< vector<int> > df_d(400001);
vector< vector<int> > df_r(400001);
vector< vector<int> > df_l(400001);
vector< vector<int> > xs_u(200001);
vector< vector<int> > xs_d(200001);
vector< vector<int> > ys_l(200001);
vector< vector<int> > ys_r(200001);


int minimum_col(const vector<int> &v1,const vector<int> &v2,int rat){
  if(!(v1.size() > 0 && v2.size() > 0))return 10000000;
  int j = 0;
  int ret = 10000000;
  REP(i,v1.size()){
    int x_ = v1[i];
    //cerr<<x_<<" "<<v2[j]<<endl;
    while(x_ > v2[j]){
      //cerr<<"dbg "<<x_<<" "<<v2[j]<<endl;
      j++;
      if(j == v2.size())return ret*rat;
    }
    ret = min(ret,v2[j] - x_);
  }
  return ret*rat;
}


int main(){
  int x[200000],y[200000];
  char u[200000];

  int n;
  cin>>n;
  REP(i,n){
    cin>>x[i]>>y[i]>>u[i];
    switch(u[i]){
      case 'U':
        pl_u[x[i]+y[i]].push_back(x[i]);
        df_u[x[i]-y[i]+OFFSET].push_back(x[i]);
        xs_u[x[i]].push_back(y[i]);
        break;
      case 'D':
        pl_d[x[i]+y[i]].push_back(x[i]);
        df_d[x[i]-y[i]+OFFSET].push_back(x[i]);
        xs_d[x[i]].push_back(y[i]);
        break;
      case 'L':
        pl_l[x[i]+y[i]].push_back(x[i]);
        df_l[x[i]-y[i]+OFFSET].push_back(x[i]);
        ys_l[y[i]].push_back(x[i]);
        break;
      case 'R':
        pl_r[x[i]+y[i]].push_back(x[i]);
        df_r[x[i]-y[i]+OFFSET].push_back(x[i]);
        ys_r[y[i]].push_back(x[i]);
        break;
    }
  }
  int ret = 10000000;

  for(auto &e : pl_u){
    sort(ALL(e));
  }
  for(auto &e : pl_d){
    sort(ALL(e));
  }
  for(auto &e : df_u){
    sort(ALL(e));
  }
  for(auto &e : df_d){
    sort(ALL(e));
  }
  for(auto &e : pl_l){
    sort(ALL(e));
  }
  for(auto &e : pl_r){
    sort(ALL(e));
  }
  for(auto &e : df_r){
    sort(ALL(e));
  }
  for(auto &e : df_l){
    sort(ALL(e));
  }
  for(auto &e : xs_u){
    sort(ALL(e));
  }
  for(auto &e : xs_d){
    sort(ALL(e));
  }
  for(auto &e : ys_l){
    sort(ALL(e));
  }
  for(auto &e : ys_r){
    sort(ALL(e));
  }

  REP(i,400001)ret = min(ret,minimum_col(pl_d[i],pl_l[i],10));
  REP(i,400001)ret = min(ret,minimum_col(df_u[i],df_l[i],10));
  REP(i,400001)ret = min(ret,minimum_col(pl_r[i],pl_u[i],10));
  REP(i,400001)ret = min(ret,minimum_col(df_r[i],df_d[i],10));
  REP(i,200001)ret = min(ret,minimum_col(xs_u[i],xs_d[i],5));
  REP(i,200001)ret = min(ret,minimum_col(ys_r[i],ys_l[i],5));
  
  if(ret >= 10000000)cout<<"SAFE"<<endl;
  else cout<<ret<<endl;
  return 0;
}
