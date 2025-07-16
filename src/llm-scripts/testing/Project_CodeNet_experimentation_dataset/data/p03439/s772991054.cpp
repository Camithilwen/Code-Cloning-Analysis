#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  cout<<0<<endl;
  string start;
  cin>>start;
  string vac="Vacant";
  if(start==vac){cout<<0<<endl;return 0;}
  int l=0,r=N;
  while(r-l>1){
    int mid=(l+r)/2;
    cout<<mid<<endl;
    string next;
    cin>>next;
    if(next==vac){cout<<mid<<endl;return 0;}
    else if(mid%2==l%2){
      if(next!=start){r=mid;}
      else{l=mid;start=next;}
    }
    else {
      if(next==start){r=mid;}
      else{l=mid;start=next;}
    }
  }

  return 0;  
}