#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	LL D; cin >> D;
	if(D%9 != 0) return cout << 0 << endl, 0;
	D /= 9;
	LL ans = 0;
	repp(i,1,19){
		LL z = 1;
		repp(k,0,i) z *= 10;
		LL x = D;
		LL a = 1;
		LL b = 1;
		while(z > 0){
			a *= 10-x%10-b;
			if(z == 1) break;
			x -= x%10*(z-1)/9;
			if(x < 0) x = -x;
			x /= 10;
			z /= 100;
			b = 0;
		}
		if(x == 0) ans += a;
	}
	cout << ans << endl;
	return 0;
}
