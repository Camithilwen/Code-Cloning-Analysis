#include<bits/stdc++.h>
const int maxn = 1001;
int vis[maxn][maxn];
int n,d1,d2;
void set(int d){
	int t = 0;
	for(;d % 4 == 0;d /= 4) ++ t;
	if(d % 4 == 1){
		for(int i = 0;i < n * 2;++i) for(int j = 0;j < n * 2;++j)
			vis[i][j] |= (i ^ j) >> t & 1;
	} else {
		for(int i = 0;i < n * 2;++i) for(int j = 0;j < n * 2;++j)
			vis[i][j] |= i >> t & 1;
	}
}
int main(){
	std::ios_base::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> d1 >> d2;
	set(d1); set(d2);
	for(int i = 0,cnt = 0;i < n * 2;++i) for(int j = 0;j < n * 2;++j)
		if(!vis[i][j]) {
			std::cout << i << ' ' << j << '\n';
			if(++cnt == n * n) return 0;
		}
}
