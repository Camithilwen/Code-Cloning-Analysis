#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) static_cast<bitset<16> >(x);
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 1000000000;
typedef double D;
const double EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
using namespace std;
//typedef pair<int, int> P;

/** Problem0546 : Lining up the cards **/

vector<string> card;
bool used[10];
set<string> ans;
int N, K;

void solve(int n, string s)
{
	if (n==K) ans.insert(s);
	else {
		rep(i, N) {
			if (!used[i]) {
				used[i] = true;
				solve(n+1, s+card[i]);
				used[i] = false;
			}
		}
	}
}

int main()
{
	while (cin>>N, N) {
		ans.clear();
		card.clear();
		fill(used, used+10, false);
		
		cin>>K;
		rep(i, N) {
			string s; cin>>s;
			card.push_back(s);
		}
		solve(0, "");
		cout << ans.size() << endl;
	}
}