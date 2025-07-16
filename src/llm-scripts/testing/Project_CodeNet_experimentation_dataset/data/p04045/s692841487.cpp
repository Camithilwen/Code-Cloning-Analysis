#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N,K;
  cin>>N>>K;
  vector<char>D(K);
  for(int i=0;i<K;i++){
    cin>>D[i];
  }
  for(int i=N;;i++){
    string t=to_string(i);
    bool use=true;
    for(int k=0;k<t.size();k++){
      bool ok=true;
      for(int j=0;j<K;j++){
        if(t[k]==D[j]){
          ok=false;
        }
      }
      if(!ok){use=false;}
    }
    if(use){cout<<t<<endl;return 0;}
  }
  return 0;
}