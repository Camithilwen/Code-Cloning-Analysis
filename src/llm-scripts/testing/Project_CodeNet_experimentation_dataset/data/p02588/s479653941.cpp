#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

int n,cnt[100][100],ma2,ma5,ans1,ans2;

signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		double x;
		scanf("%lf",&x);
		int y=floor(x*1e9+0.5),cnt2=0,cnt5=0;
		while(y%2==0) y/=2,cnt2++;
		while(y%5==0) y/=5,cnt5++;
		cnt[cnt2][cnt5]++;
		ma2=max(ma2,cnt2);
		ma5=max(ma5,cnt5);
	}
	for(int i=0;i<=ma2;i++) for(int j=0;j<=ma5;j++) if(cnt[i][j])
		for(int x=0;x<=ma2;x++) for(int y=0;y<=ma5;y++) if(cnt[x][y]&&min(i+x,j+y)>=18)
			i==x&&j==y?ans1+=cnt[i][j]*(cnt[i][j]-1)/2:ans2+=cnt[i][j]*cnt[x][y];
	write(ans2/2+ans1);
}