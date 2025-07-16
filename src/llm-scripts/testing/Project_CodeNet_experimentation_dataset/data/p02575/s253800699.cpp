#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> P;
int main(){
  long H,W;cin>>H>>W;
  set<P> S,T;
  for(long i=0;i<W;i++){S.insert(P(i,0));T.insert(P(0,i));}
  for(long k=0;k<H;k++){
    long a,b;cin>>a>>b;a--;
    long y=LONG_MAX;
    for(auto itr=S.lower_bound(P(a,-1));itr!=S.end()&&(itr->first)<b;){
      P x=*itr;
      y=min(y, x.second+b-x.first);
      T.erase(P(x.second,x.first));
      itr=S.erase(itr);
    }// ゴール: 移動回数 i,jとして, b, j+b-i, このうち, 最も移動回数が少ないものだけ残す
    if(y!=LONG_MAX&&b<W){S.insert(P(b,y)); T.insert(P(y,b));}
    cout<<(T.size()?(T.begin()->first)+k+1:-1)<<endl;
  }
}

/*

S: ゴール, 何回の移動でいけるか
T: 何回の移動でいけるか, ゴール

T.begin()を持って来ればいける
Sで更新を素早くみる





*/