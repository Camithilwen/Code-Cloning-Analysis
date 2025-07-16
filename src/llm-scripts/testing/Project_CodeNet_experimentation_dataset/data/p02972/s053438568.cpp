#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n;
  cin >> n;
  vi a(n+1);
  rep(i,n){
    int x;
    cin >> x;
    a[i+1]=x;
  }
  
  int  m=0;
  vi b(n+1);
  for(int i=n;i>0;i--){
    for(int j=2*i;j<=n;j+=i){
      a[i]^=b[j];
    }
    if(a[i]){
      m++;
      b[i]++;
    }
  }
  
  cout<<m << "\n";
  rep(i,n+1){
    if(b[i]) cout << i << ' ';
  }
  
  return 0;
}