#include <iostream>
using namespace std;

int x[100010], nx[100010][20];

int main() {
	int N, L, Q;
	cin >> N;
	for(int i=1; i<=N; ++i) cin >> x[i];
	cin >> L;
	int now=1;
	for(int i=1; i<=N; ++i){
		while(now<N){
			if(x[now+1]-x[i]<=L){
				++now;
			}
			else break;
		}
		nx[i][0]=now;
	}
	nx[N][0]=nx[N+1][0]=N+1;
	int mx=0;
	while(nx[1][mx]<N){
		for(int j=1; j<=N+1; ++j){
			nx[j][mx+1]=nx[nx[j][mx]][mx];
		}
		++mx;
	}
	cin >> Q;
	for(int q=0; q<Q; ++q){
		int a, b;
		cin >> a >> b;
		if(a>b) swap(a, b);
		int ans=0, tak=a;
		for(int i=mx; i>=0; --i){
			if(nx[tak][i]<b){
				ans |= (1<<i);
				tak=nx[tak][i];
			}
		}
		cout << ans+1 << endl;
	}
	return 0;
}