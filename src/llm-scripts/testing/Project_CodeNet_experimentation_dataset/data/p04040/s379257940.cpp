#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3e5;
const LL MOD = 1e9+7;

inline LL dmod(LL x){
	return x%MOD;
}

LL fakto[N+5];

void pre(){
	fakto[0] = 1LL;
	for(int i=1;i<=N;i++){
		fakto[i] = dmod(fakto[i-1]*(LL)(i));
	}
	return;
}

LL fe(LL x, LL y){
	if(y==0) return 1LL;
	LL ret = fe(x,y/2);
	ret = dmod(ret*ret);
	if(y&1){
		ret = dmod(ret*x);
	}
	return ret;
}

LL nCr(LL x, LL y){
	LL tmp = dmod(fakto[y]*fakto[x-y]);
	tmp = fe(tmp,MOD-2);
	tmp = dmod(tmp*fakto[x]);
	return tmp;
}

LL step(int x, int y, int a, int b){
	int dx = a-x;
	int dy = b-y;
	int tot = dx+dy;
	return nCr(tot,dx);
}

int h,w,a,b;
int main(){
	pre();
	cin >> h >> w >> a >> b;
	LL ret = 0LL;
	for(int i=1;i<=h-a;i++){
		LL tmp = step(1,1,i,b);
		tmp = dmod(tmp*step(i,b+1,h,w));
		ret = dmod(ret+tmp);
	}
	cout << ret << endl;
	return 0;
}