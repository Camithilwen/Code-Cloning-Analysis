#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
const int N=600;
int n,d1,d2,col[2][N*N];
std::vector<std::pair<int,int>> v[2];
inline int id(const int &x,const int &y) {
	return x*N+y;
}
inline bool check(const int &x) {
	return 0<=x&&x<n*2;
}
void dfs(const int &x,const int &t) {
	const int i=x/N,j=x%N;
	for(auto &d:v[t]) {
		const int nx=i+d.first,ny=j+d.second;
		if(!check(nx)||!check(ny)) continue;
		const int y=id(i+d.first,j+d.second);
		if(!col[t][y]) {
			col[t][y]=col[t][x]==1?2:1;
			dfs(y,t);
		}
	}
}
int main() {
	n=getint(),d1=getint(),d2=getint();
	for(register int i=0;i<=d1;i++) {
		const int j=sqrt(d1-i*i);
		if(i*i+j*j!=d1) continue;
		v[0].emplace_back(std::make_pair(i,j));
		v[0].emplace_back(std::make_pair(-i,j));
		v[0].emplace_back(std::make_pair(i,-j));
		v[0].emplace_back(std::make_pair(-i,-j));
	}
	for(register int i=0;i<=d2;i++) {
		const int j=sqrt(d2-i*i);
		if(i*i+j*j!=d2) continue;
		v[1].emplace_back(std::make_pair(i,j));
		v[1].emplace_back(std::make_pair(-i,j));
		v[1].emplace_back(std::make_pair(i,-j));
		v[1].emplace_back(std::make_pair(-i,-j));
	}
	for(register int i=0;i<n*2;i++) {
		for(register int j=0;j<n*2;j++) {
			if(!col[0][id(i,j)]) {
				col[0][id(i,j)]=1;
				dfs(id(i,j),0);
			}
			if(!col[1][id(i,j)]) {
				col[1][id(i,j)]=1;
				dfs(id(i,j),1);
			}
		}
	}
	for(register int i=0,cnt=0;i<n*2;i++) {
		for(register int j=0;j<n*2;j++) {
			if(col[0][id(i,j)]==1&&col[1][id(i,j)]==1) {
				printf("%d %d\n",i,j);
				if(++cnt==n*n) return 0;
			}
		}
	}
}