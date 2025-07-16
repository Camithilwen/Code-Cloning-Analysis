#include <iostream>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <sstream>
#include <istream>
#include <cmath>
#include <cstdio>

using namespace std;

#define vci vector<int>
#define vcs vector<string>
#define pb push_back
#define sz size()
#define mapii map<int, int>
#define mapci map<char, int>
#define mapsi map<string, int>
#define all(x) x.begin(), x.end()
#define minit(a, i) memset(a, i, sizeof(a));

#define for_(i, a, b) for (int i=(int)a; i<(int)b; i++)
#define for_d(i, a, b) for (int i=(int)a-1; i>=b; i--)
#define for_r(i, a, b, c) for (int i=(int)a; i<(int)b; i += c)
#define for_dr(i, a, b, c) for (int i=(int)a-1; i>=b; i -= c)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

typedef long long ll;

const int iINF = 2147483647;
const ll lINF = 9223372036854775807;

template <class T> inline void dbg(T t) { cout << t << endl; }



string ret[7] = {"null", "one pair", "two pair", "three card", "straight", "full house", "four card"};

int main() {
	vci t(5); char c;
	
	while (cin>>t[0]>>c>>t[1]>>c>>t[2]>>c>>t[3]>>c>>t[4]) {
		int ans = 0;
		
		vci v(13, 0);
		for_(i, 0, (int)t.sz) v[t[i]-1]++;
		
		int cnt = 0;
		
		// 0, 1, 2
		for_(i, 0, 13) if (v[i]==2) cnt++;
		ans = cnt;
		
		// 3
		cnt = 0;
		for_(i, 0, 13) if (v[i]==3) cnt++;
		if (cnt) ans = 3;
		
		// 4
		for_(i, 0, 10) {
			cnt = 0;
			for_(j, 0, 5) {
				if (v[(i+j)%13]==1) cnt++;
			}
			if (cnt==5) ans = 4;
		}
		
		// 5
		cnt = 0; int cnt2 = 0;
		for_(i, 0, 13) {
			if (v[i]==2) cnt++;
			if (v[i]==3) cnt2++;
		}
		if (cnt2==1 && cnt==1) ans = 5;
		
		cnt = 0;
		for_(i, 0, 13) if (v[i]==4) cnt++;
		if (cnt) ans = 6;
		
		cout << ret[ans] << endl;
	}
	
	return 0;
}