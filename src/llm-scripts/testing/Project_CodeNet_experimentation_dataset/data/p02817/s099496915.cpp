#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
#include <tuple>
using namespace std;



#define ll long long
#define ull unsigned long long
#define rep(i,N) for (ll i=0;i<N;i++)
#define loop(i,N,M) for(ll i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)
#define MP(a,b) make_pair(a,b)

ll debugFlag = false;
template<typename T> void debug(T&);
template<typename T> void debug(T&, bool);
template<typename T> void debug(vector<T>&);
template<typename T> void debug(vector<T>&, bool);
template<typename T, typename U> void debug(pair<T, U>&);
template<typename T, typename U> void debug(pair<T, U>&, bool);

template<typename T>
void debug(T& obj) {
	debug(obj, true);
}

template<typename T>
void debug(T& obj, bool lnFlag) {
	if (!debugFlag) return;
	cout << obj;
	if (lnFlag) cout << endl;
}

template<typename T>
void debug(vector<T>& obj) {
	debug(obj, true);
}

template<typename T>
void debug(vector<T>& obj, bool lnFlag) {
	if (!debugFlag) return;
	cout << "[";
	rep(i, obj.size()) {
		if (i != 0) cout << ",";
		debug(obj[i], false);
	}
	cout << "]";
	if (lnFlag) cout << endl;
}

template<typename T, typename U>
void debug(pair<T, U>& obj) {
	debug(obj, true);
}

template<typename T, typename U>
void debug(pair<T, U>& obj, bool lnFlag) {
	if (!debugFlag) return;
	cout << "(";
	debug(obj.first, false);
	cout << ",";
	debug(obj.second, false);
	cout << ")";
	if (lnFlag) cout << endl;
}

void solve() {

	string S,T;
	cin >> S >> T;
	cout << T << S;

}


int main(int argc, char* argv[]) {
	if (argc == 2 && string(argv[1]) == "debug") debugFlag = true;
	solve();
	return 0;
}