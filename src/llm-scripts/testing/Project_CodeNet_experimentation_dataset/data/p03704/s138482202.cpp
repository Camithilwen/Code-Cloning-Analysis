#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
int d[30]; 
ll f[30][2][2];

int main() {
	int D; 
	cin>>D; 
	memset(d, 0, sizeof(d)); 
	int i = 0; 
	while (D>0) {
		d[i] = D % 10; 
		D /= 10; 
		i++; 
	}
	ll ans = 0; 
	for (int len = i-1; len <= 20; ++len) {
		memset(f,0,sizeof(f)); 
		f[0][0][0] = 1; 
		for (int i = 0; i<=len/2; i++) {
			for (int l0 = 0; l0 <= 1; ++l0) 
			for (int r0 = 0; r0 <= 1; ++r0) 
			for (int l1 = 0; l1 <= 1; ++l1) 
			for (int r1 = 0; r1 <= 1; ++r1) 
				for (int x = 0+(i==0); x <= 9; ++x) 
					for (int y = 0; y <= 9; ++y) 
						if (x+d[len-i]+l1==l0*10+y && y+d[i]+r0==r1*10+x) {
							f[i+1][l1][r1] += f[i][l0][r0]; 
							if (i==len/2) {
								if (len % 2 == 0) {
									if (l1==r0 && l0==r1 && x==y) ans += f[i][l0][r0]; 
								}
								else {
									if (l1 == r1) ans += f[i][l0][r0]; 
								}
							}
						}
		}
	}
	cout<<ans<<endl; 
}
