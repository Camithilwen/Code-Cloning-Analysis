#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
	int n;
	cin>>n;
	REP(i, n) {
		int out = 0;
		int score = 0;
		vector<bool> rui(3, false);
		while(out < 3) {
			string hoge;
			cin>>hoge;
			if(hoge == "HIT") {
				if(rui[2]) {
					++score;
				}
				for(int j = 1; j >= 0; --j) {
					rui[j + 1] = rui[j];
				}
				rui[0] = true;
			} else if (hoge == "OUT") {
				++out;
			} else if(hoge == "HOMERUN") {
				score++;
				REP(j, 3) {
					if(rui[j]) ++score;
					rui[j] = false;
				}
			}
		}
		cout<<score<<endl;
	}
}