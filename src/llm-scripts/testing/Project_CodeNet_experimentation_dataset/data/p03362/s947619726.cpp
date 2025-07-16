#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll nCr(ll n,ll r){
  if(r == 1) return n;
  else if(r == 0) return 1;
  else return nCr(n-1,r-1)*n/r;
}

int main(){
  ll num[] ={7,17,37,47,67,97,107,127,137,157,167,197,227,257,277,
          307,317,337,347,367,397,457,467,487,547,557,577,587,
          607,617,647,677,727,757,787,797,827,857,877,887,907,
          937,947,967,977,997,1087,1097,1117,1187,1217,1237,
          1277,1297,1307,1327};
  
  ll n; cin >> n;
  
  rep(i,n){
    cout << num[i];
    if(i == n) cout << endl;
    else cout << ' ';
  }
  
}
  
  