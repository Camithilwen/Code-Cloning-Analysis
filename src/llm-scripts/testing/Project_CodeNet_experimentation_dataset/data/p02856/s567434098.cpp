#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll m;cin>>m;
  ll result = 0;
  ll digits_counter=-1;
  ll sum=0;
  rep(i, m){
    ll d,c;cin>>d>>c;
    digits_counter+=c;
    sum+= d*c;
  }

  if(sum%9==0)cout << sum/9+digits_counter-1 << endl;
  else cout << sum/9+digits_counter << endl;

//  cout << (sum-1)/9+digits_counter << endl;

  return 0;
}