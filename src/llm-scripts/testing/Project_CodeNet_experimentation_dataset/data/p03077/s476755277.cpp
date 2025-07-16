#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(5);
  for (int i = 0; i < 5; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  cout << (n + a[0] - 1)/a[0] + 4 << endl;
      


  return 0;
}
