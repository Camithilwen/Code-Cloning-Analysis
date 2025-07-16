#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
 
#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
// #define int ll
 
using namespace std;
typedef long long ll;
typedef long double ld;


int get(vector<pair<int, int>> have) {
	if(len(have) == 0) 
		return 0;
	if(len(have) == 1 && have[0].ft == have[0].sc) 
		return 0;
	int ans = 1;
	vector<pair<int, int>> t(len(have));
	
	for (int i = len(have) - 1; i >= 0; i--) {
		int l = 0, r = len(have) - i;
		while(r - l > 1) {
			int m = (l + r) / 2;
			if(have[i + m].ft - m >= have[i].sc) 
				r = m;
			else 
				l = m;
		}
		ans = max(ans, r);
	}
	return max(1, ans);
}

signed main() {
	#ifdef PC
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    map<char, int> was;
    vector<int> r(n + 1, -1);
    vector<pair<int, int>> have;
    for (char c = 'a'; c <= 'z'; c++)
    	was[c] = -1;
    int uk = n;
    for (int i = n - 1; i >= 0; i--) {
    	if(uk > i) 
    		uk--;
    	while(uk >= 0 && s[uk] != t[i]) 
    		uk--;
    	if(uk == -1) {
    		cout << -1;
    		return 0;
    	}
    	r[uk] = max(r[uk], i);
    }
    // for (int i = 0; i < n; i++) {
    // 	while(uk <= i && s[uk] != t[i]) 
    // 		uk++;
    // 	if(uk > i) {
    // 		cout << -1;
    // 		return -1;
    // 	}
    // 	r[uk] = i;
    // }
    // for (int i = 0; i < n; i++) {
    // 	was[s[i]] = i;
    // 	if(was[t[i]] == -1) {
    // 		cout << -1;
    // 		return 0;
    // 	}
    // 	r[was[t[i]]] = i;
    // }
    for (int i = 0; i < n; i++) {
    	if(r[i] == -1) 
    		continue;
    	have.pb({i, r[i]});
    }
    int lr = -1, rr = -1;
   	vector<pair<int, int>> now;
    int ans = 0;
    for (int i = 0; i < len(have); i++) { 
    	if(rr < have[i].ft) {
    		ans = max(ans, get(now));
    		now.clear();
    		now.pb(have[i]);
    		lr = have[i].ft, rr = have[i].sc;
    		continue;
    	}
    	now.pb(have[i]);
    	lr = have[i].ft, rr = have[i].sc;
    }
    ans = max(ans, get(now));
    cout << ans << endl;
}	