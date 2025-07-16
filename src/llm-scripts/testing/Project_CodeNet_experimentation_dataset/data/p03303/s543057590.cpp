#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	string s;
	cin >> s;
	int w;
	cin >> w;
	rep(i,s.size()){
		cout << s[i];
		i+=w-1;
	}
	cout << endl;
	return 0;
}

