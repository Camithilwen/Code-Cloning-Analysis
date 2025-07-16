/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define ssll(x,y)    scanf("%lld %lld", &x ,&y)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
    	int N, p[1001]{};
        cin >> N;
		for (int i = 2; i <= N; ++i) {
		int I = i;
		for (int j = 2, n = sqrt(I) + 1; I != 1 && j != n; ++j) {
		while (I % j == 0) {
        I /= j;
        ++p[j];
      }
    }
    if (I != 1) ++p[I];
  }
 
  cout << accumulate(begin(p), end(p), 1ll, [&](ll a, ll x) 
  {
    return a * (x + 1) % MOD;
  }) << endl;
		return 0;  
}  
