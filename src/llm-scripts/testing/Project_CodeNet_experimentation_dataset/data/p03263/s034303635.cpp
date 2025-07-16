#include<bits/stdc++.h>
using namespace std;


int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h,vector<int>(w,0));
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cin >> a[i][j];
    }
  }
  vector<tuple<int,int,int,int>> ans;
  for(int i=0;i<h;++i){
    for(int j=0;j<w-1;++j){
      if(a[i][j]%2==1){
        a[i][j]--;
        a[i][j+1]++;
        ans.push_back(make_tuple(i,j,i,j+1));
      }
    }
  }
  for(int i=0;i<h-1;++i){
    if(a[i][w-1]%2==1){
      a[i][w-1]--;
      a[i+1][w-1]++;
      ans.push_back(make_tuple(i,w-1,i+1,w-1));
    }
  }
  int n=ans.size();
  cout << n << endl;
  for(auto p : ans){
    cout << get<0>(p)+1 << " " << get<1>(p)+1 << " " << get<2>(p)+1 << " " << get<3>(p)+1 << endl;
  }
  return 0;
}
