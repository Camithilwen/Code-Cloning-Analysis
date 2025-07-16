#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> N;
  map<string,int> blue;
  string s;
  for(int i=0;i<N;++i){
    cin >> s;
    if(blue.count(s)) blue.at(s)++;
    else blue[s]=1;
  }
  cin >> M;
  map<string,int> red;
  for(int i=0;i<M;++i){
    cin >> s;
    if(red.count(s)) red.at(s)++;
    else red[s]=1;
  }

  int ans=-200;
  for(auto p: blue){
    auto word=p.first;
    auto value=p.second;
    if(red.count(word)){
      ans=max(ans,value-red.at(word));
    }
    else ans=max(ans,value);
  }

  if(ans<0) cout << 0 << endl;
  else cout << ans << endl;
  
  return 0;
}
