#include <iostream>
#include <cstdio>
#define il inline
#define ri register
using namespace std;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,d1,d2;
	scanf("%d%d%d",&n,&d1,&d2);
	int a[4]{},n1(n<<1),b1(0),b2(0);
	for(int i(d1);~i&1;++b1,i>>=1);
	for(int i(d2);~i&1;++b2,i>>=1);
	for(int i(0),j;i<n1;++i)
		for(j=0;j<n1;++j)
			++a[(b1&1?i:j-i)>>(b1>>1)&1|((b2&1?i:j-i)>>(b2>>1)&1)<<1];
	int b3(0);
	for(int i(0);i<4;++i)if(a[b3]<a[i])b3=i;
	for(int i(0),j,i1(0);i<n1;++i)
		for(j=0;j<n1;++j)
			if(((b1&1?i:j-i)>>(b1>>1)&1|((b2&1?i:j-i)>>(b2>>1)&1)<<1)==b3){
				printf("%d %d\n",i,j);
				if(++i1==n*n)return 0;
			}
	return 0;
}
