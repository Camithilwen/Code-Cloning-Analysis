#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int mask = 0;
	for(int i = 0; i < k; i ++) {
		int p;
		cin >> p;
		mask |= (1 << p);
	}

	for(int i = n; ; i ++) {
		int t = i, m = 0;
		while(t) m |= (1 << (t % 10)), t /= 10;
		if((mask & m) == 0) {
			cout << i << endl;
			break;
		}
	}

}
