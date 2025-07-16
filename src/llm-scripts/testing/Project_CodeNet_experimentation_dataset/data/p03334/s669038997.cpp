#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

LL n,d;
LL col[2][500005] = {0};
LL v[4][500005],cnt[4] = {0};

LL id(LL x,LL y){ return x * n + y + 1; } // (x,y) -> id
LL getx(LL x){ return (x - 1) / n; } // id(x,y) -> x
LL gety(LL y){ return (y - 1) % n; } // id(x,y) -> y

void dfs(LL u,LL idd){
	LL tx = getx(u),ty = gety(u);
	for(LL dy,dx = 0;dx <= n;dx ++){
		if(dx * dx > d) continue;
		dy = sqrt(d - dx * dx);
		if(dx * dx + dy * dy != d) continue;
		
		if(tx + dx < n && ty + dy < n)
			if(col[idd][id(tx + dx,ty + dy)] == -1) { col[idd][id(tx + dx,ty + dy)] = 1 - col[idd][u]; dfs(id(tx + dx,ty + dy),idd); }
		if(tx + dx < n && ty - dy >= 0)
			if(col[idd][id(tx + dx,ty - dy)] == -1) { col[idd][id(tx + dx,ty - dy)] = 1 - col[idd][u]; dfs(id(tx + dx,ty - dy),idd); }
		if(tx - dx >= 0 && ty + dy < n)
			if(col[idd][id(tx - dx,ty + dy)] == -1) { col[idd][id(tx - dx,ty + dy)] = 1 - col[idd][u]; dfs(id(tx - dx,ty + dy),idd); }
		if(tx - dx >= 0 && ty - dy >= 0)
			if(col[idd][id(tx - dx,ty - dy)] == -1) { col[idd][id(tx - dx,ty - dy)] = 1 - col[idd][u]; dfs(id(tx - dx,ty - dy),idd); }
	}
}

int main(){
	memset(col,-1,sizeof(col));
	cin >> n; n <<= 1;
	cin >> d;
	for(LL i = 0;i < n;i ++)
		for(LL j = 0;j < n;j ++)
			if(col[0][id(i,j)] == -1){ col[0][id(i,j)] = 1; dfs(id(i,j),0); }
	cin >> d;
	for(LL i = 0;i < n;i ++)
		for(LL j = 0;j < n;j ++)
			if(col[1][id(i,j)] == -1){ col[1][id(i,j)] = 1; dfs(id(i,j),1); }
	/*
	for(LL i = 0;i < n;i ++)
		for(LL j = 0;j < n;j ++)
			cout << col[0][id(i,j)] << (j == n - 1 ? '\n' : ' ');
	for(LL i = 0;i < n;i ++)
		for(LL j = 0;j < n;j ++)
			cout << col[1][id(i,j)] << (j == n - 1 ? '\n' : ' ');
	*/
	for(LL i = 1;i <= id(n - 1,n - 1);i ++){
		LL co = col[0][i] + col[1][i] * 2;
		v[co][++ cnt[co]] = i;
	}
	for(LL i = 0;i < 4;i ++){
		if(cnt[i] >= n * n / 4){
			for(LL j = 1;j <= n * n / 4;j ++) cout << getx(v[i][j]) << ' ' << gety(v[i][j]) << '\n';
			break;
		}
	}
	return 0;
}