#include "bits/stdc++.h"

using namespace std;

const int N=300005;
const int p=1e9+7;

inline void add(int& a,const int& b){
	a+=b;
	if(a>=p)a-=p;
}

int to[8][2]={{5,1},{3,2},{2,2},{4,1},{3,3},{7,6},{5,1},{5,5}};

char s[N];

int f[N][8];

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		if(s[i]!='1')for(int j=0;j<8;++j)add(f[i][to[j][0]],f[i-1][j]);
		if(s[i]!='0')for(int j=0;j<8;++j)add(f[i][to[j][1]],f[i-1][j]);
	}
	printf("%d\n",(f[n][1]+f[n][2])%p);
	return 0;
}
