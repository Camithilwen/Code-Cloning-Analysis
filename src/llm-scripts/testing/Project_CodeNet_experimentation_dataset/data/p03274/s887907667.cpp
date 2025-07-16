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
  int N, K; cin >> N >> K;
  int x[N]; rep(i,N) cin >> x[i];
  int ans = 1000000000;
  rep(i,N-K+1){
    int MAX = x[i+K-1], MIN = x[i];
    int tmp;
    if (MIN > 0 || MAX<0 ){
      tmp = max(abs(MIN), abs(MAX));
    } 
    else {
      tmp = MAX - MIN + min(MAX, abs(MIN));
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
