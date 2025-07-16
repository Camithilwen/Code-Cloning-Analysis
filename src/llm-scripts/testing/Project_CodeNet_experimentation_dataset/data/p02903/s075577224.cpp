#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
using namespace std;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<int> vint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<string> vstring;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define yes(ans) if(ans)cout<<"yes"<<endl;else cout<<"no"<<endl;
#define Yes(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define POSSIBLE(ans) if(ans)cout<<"POSSIBLE"<<endl;else cout<<"IMPOSSIBLE"<<endl;
#define Pi 3.1415926535897932384626
#define mod llint(1e9+7)
#define Inf 2147483647
#define llInf 9223372036854775807

int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	string ans = "";
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (j <= a && i <= b) {
				ans += "0";
			}
			else if (j > a&& i > b) {
				ans += "0";
			}
			else {
				ans += "1";
			}
		}
		ans += "\n";
	}
	cout << ans << endl;
	return 0;
}

