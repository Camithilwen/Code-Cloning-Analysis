#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,m;
  cin>>a>>b>>m;
  vector<int> ai(a);
  int ma;
  vector<int> bi(b);
  int mb;
  for(int i=0;i<a;i++){
    cin>>ai.at(i);
    ma=(i==0?ai.at(i):min(ma,ai.at(i)));
  }
  for(int i=0;i<b;i++){
    cin>>bi.at(i);
    mb=(i==0?bi.at(i):min(mb,bi.at(i)));
  }
  int ms=ma+mb;
  for(int _=0;_<m;_++){
    int x,y,c;
    cin>>x>>y>>c;
    x--;
    y--;
    ms=min(ms,ai.at(x)+bi.at(y)-c);
  }
  cout<<ms<<endl;
}