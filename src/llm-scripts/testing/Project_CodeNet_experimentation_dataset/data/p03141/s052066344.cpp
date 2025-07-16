#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> vec;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    vec.push_back(make_tuple(a+b, a, b));
  }
  sort(all(vec), greater<tuple<ll, ll, ll>>());
  ll sumA=0, sumB=0;
  rep(i, n){
   	 if(i%2==0){
       sumA += get<1>(vec[i]);
     }else{
       sumB += get<2>(vec[i]);
     }
  }
  cout << sumA-sumB << endl;
  return 0;
}