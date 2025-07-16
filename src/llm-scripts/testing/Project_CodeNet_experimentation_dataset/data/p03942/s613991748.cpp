#include<bits/stdc++.h>
#define mo 998244353
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,i,j,r[1000005],top,x[1000005],y[1000005];
long long head,tail,sum,max1,zhan[1000005];
char s[1000005],t[1000005];
int main(){
	n=read();
	scanf("%s%s",s+1,t+1);
	for(i=1;i<=n;i++)
		if(s[i]!=t[i])
			break;
	if(i==n+1){
		pus(0,2);
		return 0;
	}
	j=n;
	for(i=n;i>=1;i--){
		if(i<j)
			j=i;
		while(j!=0&&t[i]!=s[j])
			j--;
		if(j==0){
			pus(-1,2);
			return 0;
		}
		if(r[j]==0)
			r[j]=i;
	}
	for(i=1;i<=n;i++)
		if(r[i]!=0){
			top++;
			x[top]=i;
			y[top]=r[i];
		}
	head=1;
	for(i=top;i>=1;i--){
		while(head<=tail&&y[i]<zhan[head]-sum)
			head++;
		tail++;
		sum++;
		zhan[tail]=x[i]+sum;
		max1=max(max1,tail-head+1);
	}
	pus(max1,2);
	return 0;
}