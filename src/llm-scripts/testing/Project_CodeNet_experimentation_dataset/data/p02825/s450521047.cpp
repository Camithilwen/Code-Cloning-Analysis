#include <cstdio>
#include <cstring>

char ans3[4][4]={"aab","b.b","baa"};
char ans4[5][5]={"aacd","bbcd","dcaa","dcbb"};
char ans5[6][6]={"aabc.","..bcd","ccd.d","d.daa","dccbb"};
char ans6[7][7]={"a..bcc","a..bdd",".bccb.",".baab.","ddb..a","ccb..a"};
char ans7[8][8]={"aacd...","bbcd...","ccaab..","..b.bdd","..baacc","....cba","....cba"};

char s[1010][1010];

inline void paint3(int x){ for(int i=0;i<3;++i) for(int j=0;j<3;++j) s[x+i][x+j]=ans3[i][j]; }
inline void paint4(int x){ for(int i=0;i<4;++i) for(int j=0;j<4;++j) s[x+i][x+j]=ans4[i][j]; }
inline void paint5(int x){ for(int i=0;i<5;++i) for(int j=0;j<5;++j) s[x+i][x+j]=ans5[i][j]; }
inline void paint6(int x){ for(int i=0;i<6;++i) for(int j=0;j<6;++j) s[x+i][x+j]=ans6[i][j]; }
inline void paint7(int x){ for(int i=0;i<7;++i) for(int j=0;j<7;++j) s[x+i][x+j]=ans7[i][j]; }

int main(){
	int n; scanf("%d",&n); if(n==2){ puts("-1"); return 0; }
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) s[i][j]='.';
	if(n%6==0){ for(int i=0;i<n/6;++i) paint6(6*i); }
	if(n%6==1){ for(int i=0;i<n/6-1;++i) paint6(6*i); paint7(n-7); }
	if(n%6==2){ for(int i=0;i<n/6-1;++i) paint6(6*i); paint4(n-8); paint4(n-4); }
	if(n%6==3){ for(int i=0;i<n/3;++i) paint3(3*i); }
	if(n%6==4){ for(int i=0;i<n/6;++i) paint6(6*i); paint4(n-4); }
	if(n%6==5){ for(int i=0;i<n/6;++i) paint6(6*i); paint5(n-5); }
	for(int i=0;i<n;++i){ for(int j=0;j<n;++j) printf("%c",s[i][j]); puts(""); }
	return 0;
}