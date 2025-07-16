#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5500+5,M=1500,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int sx,sy,ex,ey;
int main(){
	cin>>sx>>sy>>ex>>ey;
	for(int i=0;i<ey-sy;i++)	putchar('U');
	for(int i=0;i<ex-sx;i++) putchar('R');
	for(int i=0;i<ey-sy;i++)	putchar('D');
	for(int i=0;i<ex-sx;i++) putchar('L');
	putchar('L');
	for(int i=0;i<=ey-sy;i++)	putchar('U');
	for(int i=0;i<=ex-sx;i++) putchar('R');
	putchar('D');
	putchar('R');
	for(int i=0;i<=ey-sy;i++)	putchar('D');
	for(int i=0;i<=ex-sx;i++) putchar('L');
	putchar('U');
	return 0;
}