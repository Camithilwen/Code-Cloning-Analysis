#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char s[300020];
int t[8][2];
int n,f[300020][8];

inline void pre(){
	t[0][0]=2;t[0][1]=1;
	t[1][0]=3;t[1][1]=5;
	t[2][0]=4;t[2][1]=7;
    t[3][0]=6;t[3][1]=1;
	t[4][0]=2;t[4][1]=2;
	t[5][0]=5;t[5][1]=5;
	t[6][0]=3;t[6][1]=3;
	t[7][0]=2;t[7][1]=1;
}

int main() {
	int i,j;
	pre();
	scanf("%s",s);
	n=strlen(s);
	f[n][1]=1;
	f[n][5]=1;
	for(i=n-1;i>=0;--i){
		for(j=0;j<8;++j){
			if(s[i]!='1')
				f[i][j]+=f[i+1][t[j][0]];
			if (s[i]!='0')
				f[i][j]+=f[i+1][t[j][1]];
			f[i][j]%=mod;
		}
	}
	printf("%d\n", f[0][0]);
}