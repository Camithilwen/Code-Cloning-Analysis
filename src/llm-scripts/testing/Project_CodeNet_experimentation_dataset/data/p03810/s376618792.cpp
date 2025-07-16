//what is going on
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
vl w;
int gcd(int a, int b) {
	if(a == 0) {return b;}
	if(b == 0) {return a;}
	return gcd(b,a%b);
}
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		ll t;
		cin >> t;
		w.push_back(t);
	}
	int lob = 0;
		for(int j=0;j<n;j++) {
			if(w[j]&(1)) {
				lob++;
			}
		}
	int poss = 0;
	if(lob != 1) {
		poss = (n-lob)&1;
	} else {
		if(n&1) {
			int ct = 0;
			int cob = 0;
			while(1) {
				int mo = 0;
				lob = 0;
				for(int i=0;i<n;i++) {
					if(w[i]&1) {lob++;
						mo = i;
					}
				}
				if(lob != 1) {
					cob = n-lob;
					break;
				}
				if(w[mo] == 1) {
					cob = 0;
					break;
				}
				ct++;
				w[mo]--;
				int g = w[0];
				for(int i=1;i<n;i++) {
					g = gcd(w[i],g);
				}
				for(int i=0;i<n;i++) {
					w[i] /= g;
				}
			}
			poss = (cob+ct)&1;
		} else {
			poss = (n-lob)&1;
		}
	}
	if(poss) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
}
