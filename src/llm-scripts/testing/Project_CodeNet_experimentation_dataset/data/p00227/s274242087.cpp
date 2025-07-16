#include<cstdio>
#include<algorithm>
#include<functional>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

int main(){
	for(int n,m;scanf("%d%d",&n,&m),n;){
		int p[1000];
		rep(i,n)	scanf("%d",p+i);

		sort(p,p+n,greater<int>());

		int total=0;
		rep(i,n) if((i+1)%m!=0) total+=p[i];
		printf("%d\n",total);
	}

	return 0;
}