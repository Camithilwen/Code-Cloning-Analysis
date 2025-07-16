#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<n; i++)

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	rep(i, N) {
		cin >> v.at(i);
	}

	int a=0, b=0, c=0, x, y, z;
    rep(i, min(K,50)) {
        vector<int> vv(N+1);
        rep(j, N) {
            x = v.at(j);
            vv.at(max(j-x,  0)) += 1;
            vv.at(min(j+x+1,N)) -= 1;
        }
        v.at(0) = vv.at(0);
        rep1(j, N) {
            v.at(j) = v.at(j-1) + vv.at(j);
        }
    }

    rep(i, N) {
        cout << v.at(i) << " ";
    }
}
