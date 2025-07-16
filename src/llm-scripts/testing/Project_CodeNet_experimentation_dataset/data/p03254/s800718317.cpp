#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
   int n,x;
   cin >> n >>x;
   vector<int>a(n);
   rep(i,n)cin >> a[i];
   sort(a.begin(),a.end());
   int cnt=0;
   rep(i,n-1){
       if(x<a[i]) break;
       x-=a[i];
       cnt++;
   }
   if(a[n-1]==x) cnt++;
   cout << cnt <<endl;
}