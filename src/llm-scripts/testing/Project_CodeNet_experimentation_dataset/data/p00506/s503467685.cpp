#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>
 
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define MP make_pair
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;

const int INF = 1<<29;

int gcd(int m, int n){
	return (n==0?m:gcd(n, m%n));
}

int main(){
	int n, a, b;
	cin >> n >> a;
	rep(i, n-1){
		cin >> b;
		a = gcd(a, b);
	}

	vector<int> ans;
	FOR(i, 1, sqrt(1.*a)+1){
		if(a%i == 0){
			ans.push_back(i);
			ans.push_back(a/i);
		}
	}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	rep(i, ans.size()){
		cout << ans[i] << endl;
	}

    return 0;
}