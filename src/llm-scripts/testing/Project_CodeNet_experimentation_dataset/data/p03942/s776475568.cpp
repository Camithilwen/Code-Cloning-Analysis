#include <algorithm>
#include <cstdio>
const int N=1000005;
int f[N];
char a[N],b[N];
bool check(int n){
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	int n;scanf("%d\n%s%s",&n,a+1,b+1);
	if (check(n)){
		printf("0\n");
		return 0;
	}
	int ans=1;
	for (int i=n,j=n,x=0;i;i--)
	if (b[i]!=b[i-1]){
		for (j=std::min(j,i);j && a[j]!=b[i];j--) f[j+x]=-x;
		if (!j){
			printf("-1\n");
			return 0;
		}
		x++;
		if (j--<i) ans=std::max(ans,f[i-1+x]+x+1);
	}
	printf("%d\n",ans);
}