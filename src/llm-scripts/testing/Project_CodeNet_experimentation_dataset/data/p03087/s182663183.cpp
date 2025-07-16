#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  int c[N];
  c[0] = 0;
  rep(i,N-1) {
    if (S.substr(i,2)=="AC") c[i+1] = 1;
    else c[i+1] = 0;
  }
  rep(i,N){
    if (i==0) continue;
    else c[i] += c[i-1];
  }
  
  rep(q,Q){
    int l, r;
    cin >> l >> r;
    cout << c[r-1] - c[l-1] << endl;
  }
  


  // cout << fixed << setprecision(10);
  
  return 0;
}
