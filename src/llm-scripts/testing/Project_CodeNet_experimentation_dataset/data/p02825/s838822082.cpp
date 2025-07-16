#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,flag;
char s[1010][1010],ans[1010][1010];
void solve7() {
	m=7;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) s[i][j]='.';
	for (int i=1;i<m;i+=3)
		for (int j=1;j<m;j+=3) {
			s[i][j+1]=s[i][j+2]='a';
			s[i+1][j]=s[i+2][j]='b';
		}
	char ch='c';
	for (int i=1;i<m;i+=2) {
		s[i][m]=ch,s[i+1][m]=ch;
		if (ch=='c') ch='d'; else ch='c';
	}
	ch='c';
	for (int i=1;i<m;i+=2) {
		s[m][i]=ch,s[m][i+1]=ch;
		if (ch=='c') ch='d'; else ch='c';
	}
}
void solve6() {
	m=6;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) s[i][j]='.';
	s[1][1]=s[1][2]='a';
	s[1][5]=s[1][6]='b';
	s[2][4]=s[2][5]='c';
	s[4][2]=s[4][3]='d';
	s[5][1]=s[5][2]='e';
	s[6][5]=s[6][6]='f';
	s[2][1]=s[3][1]='g';
	s[1][3]=s[2][3]='h';
	s[3][6]=s[4][6]='i';
	s[3][4]=s[4][4]='j';
	s[5][3]=s[6][3]='k';
	s[5][4]=s[6][4]='l';
}
void solve5() {
	m=5;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) s[i][j]='.';
	for (int i=1;i<=m;i+=5)
	for (int j=1;j<=m;j+=5) {
		s[i][j]=s[i][j+1]='a';
		s[i][j+2]=s[i][j+3]='b';
		s[i][j+4]=s[i+1][j+4]='c';
		s[i+1][j]=s[i+2][j]='d';
		s[i+1][j+2]=s[i+1][j+3]='e';
		s[i+2][j+1]=s[i+3][j+1]='f';
		s[i+2][j+4]=s[i+3][j+4]='g';
		s[i+3][j]=s[i+4][j]='i';
		s[i+4][j+1]=s[i+4][j+2]='j';
		s[i+4][j+3]=s[i+4][j+4]='h';
	}
}
void solve4() {
	m=4;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) s[i][j]='.';
	s[1][1]=s[1][2]='a';
	s[1][3]=s[2][3]='b';
	s[1][4]=s[2][4]='c';
	s[2][1]=s[2][2]='d';
	s[3][1]=s[4][1]='e';
	s[3][2]=s[4][2]='f';
	s[3][3]=s[3][4]='g';
	s[4][3]=s[4][4]='h';
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	if (n==2) { printf("-1\n"); return 0; }
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) ans[i][j]='.';
	if (n%3==0) {
		for (int i=1;i<=n;i+=3)
		for (int j=1;j<=n;j+=3) {
			ans[i][j+1]=ans[i][j+2]='a';
			ans[i+1][j]=ans[i+2][j]='b';
		}
	} else {
		int t=n/4-1;
		solve4();
		for (int i=1;i<=t*4;i+=4) {
			for (int x=1;x<=4;x++)
			for (int y=1;y<=4;y++)
				ans[i+x-1][i+y-1]=s[x][y];
		}
		t=n-t*4;
		if (t==4) solve4();
		else if (t==5) solve5();
		else if (t==6) solve6();
		else solve7();
		int i=1+(n/4-1)*4;
		for (int x=1;x<=t;x++)
		for (int y=1;y<=t;y++)
			ans[i+x-1][i+y-1]=s[x][y];
	}
	for (int i=1;i<=n;i++)
		printf("%s\n",ans[i]+1);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/