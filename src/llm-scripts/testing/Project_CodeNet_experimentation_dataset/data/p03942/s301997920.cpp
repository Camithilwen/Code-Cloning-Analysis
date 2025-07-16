//神题
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int n, ff, op, cl, d[N], ans, L, R, now;
char s1[N], s2[N];
int main(){
	scanf("%d%s%s", &n, s1+1, s2+1); s2[0]='$';
	ff=1; for(int i=1; i<=n; i++)if(s1[i]!=s2[i]){ff=0; break;}
	if(ff){printf("0"); return 0;}
	now=n; R=n;
	op=1; cl=ans=0;
	for(int i=n-1; i>=0; i--)if(s2[i]!=s2[i+1]){
		L=i+1;
		while(now&&(now>L||s1[now]!=s2[L]))now--;
		if(!now){printf("-1"); return 0;}
		while(op<=cl&&R<d[op]-(cl-op))op++;
		d[++cl]=now;
		ans=max(ans, cl-op+1);
		now--; R=i;
	}
	printf("%d", ans);
	return 0;
}