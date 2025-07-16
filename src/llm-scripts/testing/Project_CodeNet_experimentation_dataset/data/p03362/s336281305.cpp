#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 2; i <= 55555; i++){
		if(i%5 != 1) continue;
		if(isPrime(i)){
			cout << i << endl;
			n--;
		} 
		if(n == 0) break;
	} 
}
