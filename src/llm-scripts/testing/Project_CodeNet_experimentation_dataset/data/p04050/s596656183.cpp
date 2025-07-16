#include <bits/stdc++.h>
using namespace std;
#define rg register

template <typename _Tp> inline _Tp read(_Tp&x){
	char c11=getchar();x=0;while(!isdigit(c11))c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();return x;
}

int n,m,tot,a[105];

int main(){
	read(n),read(m);
	for(rg int i=1;i<=m;i++)read(a[i]),tot+=(a[i]&1);
	if(tot>2){puts("Impossible");return 0;}
	if(tot){
		bool flag=0;
		for(rg int i=1;i<m;i++)
			if(a[i]&1)
				if(flag)swap(a[i],a[m]);
				else flag=1,swap(a[i],a[1]);
	}
	if(m==1){
		if(a[1]==1){puts("1\n1\n1");return 0;}
		printf("%d\n",a[1]);puts("2");
		printf("1 %d\n",a[1]-1);
		return 0;
	}
	for(rg int i=1;i<=m;i++)printf("%d ",a[i]);
	if(a[m]==1){
		printf("\n%d\n",m-1);
		printf("%d\n",a[1]+1);
		for(rg int i=2;i<m;i++)printf("%d ",a[i]);
	}
	else {
		printf("\n%d\n",m);
		printf("%d\n",a[1]+1);
		for(rg int i=2;i<m;i++)printf("%d ",a[i]);
		printf("%d\n",a[m]-1);
	}return 0;
}