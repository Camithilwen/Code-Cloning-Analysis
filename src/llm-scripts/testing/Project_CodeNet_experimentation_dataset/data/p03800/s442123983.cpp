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

vector<int> sw(100010,0);
const int dx[] = {1,0,1,0};
const int dy[] = {1,1,0,0};
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	rep(i,4){
		sw[0] = dx[i];
		sw[1] = dy[i]; 
		for(int j = 1; j < n -1; j++){
			if(sw[j]){
				// j匹目が羊の時、発言は真
				if(s[j]=='o'){
					sw[j+1] = sw[j-1];
				} else {
					sw[j+1] = 1 - sw[j-1];
				}
			} else {
				// j匹目が狼の時、発言は偽
				if(s[j] == 'o'){
					sw[j+1] = 1 - sw[j-1];
				} else {
					sw[j+1] = sw[j-1];
				}
			}
		}
		// n - 1 匹目の証言があっているかを確かめる。
		if(sw[0]){
			if(s[0] == 'o'){
				if(sw[1] == sw[n-1]){
					// OK
				} else {
					// NO
					continue;
				}
			} else {
				if(sw[1] != sw[n-1]){
				} else {
					// NO
					continue;
				}
			}
		} else {
			// n - 1 匹目狼
			if(s[0] == 'x'){
				if(sw[1] == sw[n-1]){
				} else {
					// NO
					continue;
				}
			} else {
				if(sw[1] != sw[n-1]){
				} else {
					// NO
					continue;
				}
			}
		}// n - 1 匹目の証言があっているかを確かめる。
		if(sw[n-1]){
			if(s[n-1] == 'o'){
				if(sw[0] == sw[n-2]){
					// OK
				} else {
					// NO
					continue;
				}
			} else {
				if(sw[0] != sw[n-2]){
				} else {
					// NO
					continue;
				}
			}
		} else {
			// n - 1 匹目狼
			if(s[n-1] == 'x'){
				if(sw[0] == sw[n-2]){
				} else {
					// NO
					continue;
				}
			} else {
				if(sw[0] != sw[n-2]){
				} else {
					// NO
					continue;
				}
			}
		}
		rep(j,n){
			if(sw[j]){
				cout << 'S';
			} else {
				cout << 'W';
			}
		} cout << endl;
		return 0;
	} 
	cout << -1 << endl;
}
