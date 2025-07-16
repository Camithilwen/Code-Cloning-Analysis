#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n;
  cin >> n;
  string s="";
  ll m=1;
  if(n==0){
    cout << 0 << endl;
    return 0;
  }
  while(n!=0){
    if(abs(n)%(abs(m)*2)!=0){
      s='1'+s;
      n-=m;
    }
    else s='0'+s;
    m*=-2;
  }
  cout << s << endl; 
}  
