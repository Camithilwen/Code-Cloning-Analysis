#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

vector<vector<string>>boards={
{},{},{},
{
"aab",
"c.b",
"cdd"
},
{
"abcc",
"abdd",
"eefg",
"hhfg",
},
{
"abc..",
"abc..",
"deeff",
"d.ghh",
"iigjj"
},
{
"abc...",
"abc...",
"d.eeff",
"dghh..",
".g.ijj",
"kk.ill",
},
{
"abc....",
"abc....",
"def....",
"def....",
"g..hhii",
"g..jjkk",
".llmmnn",
}
};

int n;
char ans[2000][2000];

void print(int x,int y,int d){
	rep(i,d)rep(j,d){
		ans[x+i][y+j]=boards[d][i][j];
	}
}
void answer(){
	rep(i,n)printf("%s\n",ans[i]);
	exit(0);
}

int main(){
	cin>>n;
	if(n==2){puts("-1");return 0;}
	rep(i,n)rep(j,n)ans[i][j]='.';
	if(n==3){
		print(0,0,3);
		answer();
	}
	int x=0;
	while(1){
		if(n-x>=8){
			print(x,x,4);
			x+=4;
		}
		else{
			print(x,x,n-x);
			answer();
		}
	}
}