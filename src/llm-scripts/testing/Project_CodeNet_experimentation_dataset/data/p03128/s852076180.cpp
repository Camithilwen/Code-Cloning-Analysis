#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> v = {2,5,5,4,5,6,3,7,6};
  
  int n,m;
  cin >> n >> m;
  int use = 0;
  rep(i,m){
    int a;
    cin >> a;--a;
    use |= (1<<a);
  }
//  cout << bitset<9>(use) << endl;
  vector<int> dp(n+1,-INT_MAX/5);
  dp[0] = 0;
  rep(i,n+1){
    for(int j=8;j>=0;j--){
      if((1<<j) & use) {
	int nidx = i + v[j];
	if(nidx<=n){
	  dp[nidx] = max(dp[nidx],dp[i]+1);
	  //	  cout << "i ni dpni " << i << " " << nidx << " " << dp[nidx] << endl;
	}
      }
    }
  }
  int cidx = n;
  while(cidx!=0){
    for(int j=8;j>=0;j--){
      if((1<<j) & use) {
	int nidx = cidx - v[j];
	if(nidx>=0 && dp[nidx] +1 == dp[cidx]){
	  cidx=nidx;
	  cout << j+1;
	  break;
	}
      }
    }
  }
  cout << endl;
  //  cout << dp[n] << endl;

  
  return 0;
    

}
