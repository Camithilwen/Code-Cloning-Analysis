#include <bits/stdc++.h>

using namespace std;

map<int, int> num, pos;
set<int> s;
vector<int> v;

const int N = 1e5+10;
const int k = 30;

int up[N][k];
int L;
void calc(int i) {
	//cout << "this->" << *s.lower_bound(-(v[i]+L)) << endl;
	up[i][0] = num[*s.lower_bound(-(v[i]+L))];
	//cout << up[i][0] << endl;
	for(int j = 1; j < k; j++) {
		up[i][j] = up[up[i][j-1]][j-1];
	}
	/*cout << "i=" << i << ": " <<  endl;
	for(int j = 0; j < k; j++) cout << "k=" << j << " " << up[i][j] << endl;
	cout << endl;
	*/
}

int solve(int a, int b) {
	if(a>b) swap(a, b);
	int sum = 0;
	int cur = a;
	while(cur != b) {
		for(int j = 0; j < k-1; j++) {
			if(up[cur][j] >= b) {
				if(j==0) {
					sum++;
					cur = b;
				} else {
					cur = up[cur][j-1];
					sum += (1<<(j-1));
				}
				break;
			}
		}
	}

	return sum;
}

int main() {
	int n; cin >> n;
	v.resize(n+1);
	int cnt = 1;
	for(int i = 1; i <= n; i++) {
		int xi; cin >> xi;
		num[-xi] = cnt;
		pos[cnt] = xi;
		cnt++;
		s.insert(-xi);
		v[i] = xi;
	}
	cin >> L;
	for(int i = 0; i < k; i++) up[n+1][i] = n; 
	for(int i = n; i > 0; i--) {
		calc(i);
	}

	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		cout << solve(a, b) << "\n";
	}
}