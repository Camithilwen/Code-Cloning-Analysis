#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> ab(n),cd(n);
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    ab[i]=make_pair(b,a);
  }
  for(int i=0;i<n;++i){
    int c,d;
    cin >> c >> d;
    cd[i]=make_pair(c,d);
  }
  sort(ab.begin(),ab.end(),greater<pair<int,int>>());
  sort(cd.begin(),cd.end());

  vector<bool> f(n,false);
  int cnt=0;

  for(int i=0;i<n;++i){
    int c=cd[i].first;
    int d=cd[i].second;
    for(int j=0;j<n;++j){
      int b=ab[j].first;
      int a=ab[j].second;
      if(f[j])continue;
      if(a<c && b<d){
        f[j]=true;
        cnt++;
        break;
      }
    }
  }
  //int cnt=0;
  //for(int i=0;i<n;++i)if(f[i])cnt++;

  cout << cnt << endl;
  return 0;

}
