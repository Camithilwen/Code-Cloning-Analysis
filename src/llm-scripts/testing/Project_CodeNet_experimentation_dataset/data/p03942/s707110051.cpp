#include <bits/stdc++.h>
using namespace std;
#define N 1000010
inline int read() {
	int x=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int x[N];
char s[N],t[N];
int main() {
	int n=read(),p=0;
	scanf("%s%s",&s,&t);
	for (int i=n-1,j=n,k=0,l=0;i>=0;i--) {
	   	if (j>i && t[i]!=s[i]) j=i;
	   	if (j<=i && t[i]!=s[j]) {
			for (;j>=0 && t[i]!=s[j];j--);
			if (j<0) return puts("-1"),0;
			k++,l++,x[j+l]++,p=max(p,k);
		}
	   	k-=x[i+l],x[i+l]=0;
    }
    printf("%d\n",p);
	return 0;
}