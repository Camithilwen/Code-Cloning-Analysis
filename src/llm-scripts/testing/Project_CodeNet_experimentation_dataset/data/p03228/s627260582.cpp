#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll a, b, k;
	cin >> a >> b >> k;
	int count = 1;
	while(k--){
		if(count%2){
			// a をそうさ
			if(a%2) a--;
			b += a/2;
			a /= 2;
		} else{
			if(b%2) b--;
			a += b/2;
			b /= 2;
		}
		count ++ ;
	}
	cout << a << " " << b << endl; 
}
