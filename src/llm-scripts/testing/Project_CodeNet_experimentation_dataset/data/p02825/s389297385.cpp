#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	int s[1009][1009];
	char c[1009][1009];
	char c4[10][10]={
		{'a','a','b','c'},
		{'d','d','b','c'},
		{'b','c','a','a'},
		{'b','c','d','d'}
	};
	char c5[10][10]={
		{'a','a','b','b','a'},
		{'b','c','c','.','a'},
		{'b','.','.','c','b'},
		{'a','.','.','c','b'},
		{'a','b','b','a','a'}
	};
	char c7[10][10]={
		{'a','a','b','b','c','c','.'},
		{'d','d','.','d','d','.','a'},
		{'.','.','d','.','.','d','a'},
		{'.','.','d','.','.','d','b'},
		{'d','d','.','d','d','.','b'},
		{'.','.','d','.','.','d','c'},
		{'.','.','d','.','.','d','c'}
	};
	int main(){
		int n=read<int>();
		if(n<=2) puts("-1"),exit(0);
		else if(n%3==0){
			for(int i=1;i<=n;i+=3)
				s[i][i]=s[i][i+1]=s[i+1][i+2]=s[i+2][i+2]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(s[i][j]) printf("a");
					else printf(".");
				}
				cout<<endl;
			}
		}else{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) c[i][j]='.';

			int x=0,y=0,z=0,peg=0;
			for(x=0;x<=n/4;x++){
				for(y=0;x*4+y*5<=n;y++){
					int now=n-x*4-y*5;
					z=now/7;
					if(z*7==now){peg=1;break;}
				}
				if(peg) break;
			}

			for(int i=1;i<=x;i++){
				int now=i*4-3;
				for(int j=now;j<=i*4;j++)
					for(int k=now;k<=i*4;k++)
						c[j][k]=c4[j-now][k-now];
			}
			for(int i=1;i<=y;i++){
				int now=x*4+i*5-4;
				for(int j=now;j<=x*4+i*5;j++)
					for(int k=now;k<=x*4+i*5;k++)
						c[j][k]=c5[j-now][k-now];
			}
			for(int i=1;i<=z;i++){
				int now=x*4+y*5+i*7-6;
				for(int j=now;j<=x*4+y*5+i*7;j++)
					for(int k=now;k<=x*4+y*5+i*7;k++)
						c[j][k]=c7[j-now][k-now];
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					printf("%c",c[i][j]);
				}
				puts("");
			}
		}
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}