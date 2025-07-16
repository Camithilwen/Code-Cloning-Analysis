#include<cstdio>
const int N=1e5+5;
int n,i,a[N],ans;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	for (n=read(),i=1;i<=n;i++) a[i]=read();
	if (n==1){puts("Second");return 0;}
	for (;;){
		int k0=0,k1=0,x;
		for (i=1;i<=n;i++)
			if (a[i]&1) k1++,x=i; else k0++;
		if (k0&1){ans^=1;break;}
		if (k1>1||a[x]==1) break;
		a[x]--;int k=a[1];ans^=1;
		for (i=2;i<=n&&k>2;i++) k=gcd(k,a[i]);
		for (i=1;i<=n;i++) a[i]/=k;
	}
	puts(ans?"First":"Second");
}