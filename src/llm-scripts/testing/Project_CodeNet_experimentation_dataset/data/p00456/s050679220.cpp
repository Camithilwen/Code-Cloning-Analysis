#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	int n = 10;
	vector<int> a(n), b(n);

	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());

	cout << a[0] + a[1] + a[2] << " " << b[0] + b[1] + b[2] << endl;

	return 0;
}