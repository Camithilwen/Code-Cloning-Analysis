#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;i++)
struct rec{int di,h;};
vector<rec> vc;
bool comp(rec const &l,rec const &r){
	return l.di!=r.di ? l.di<r.di : l.h<r.h;
}
int main(){
	rep1(i,150) rep1(j,i-1) vc.push_back({i*i+j*j,j});
	sort(vc.begin(),vc.end(),comp);
	while(true){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==0) break;
		rec e={n*n+m*m,n};
		rec rc=*upper_bound(vc.begin(),vc.end(),e,comp);
		printf("%d %d\n",rc.h,(int)((1e-9)+sqrt(rc.di-rc.h*rc.h)));
	}
	return 0;
}