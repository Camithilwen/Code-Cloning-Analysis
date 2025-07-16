#include<bits/stdc++.h>
using namespace std;
#define N 305
double dp[N][N][N];
int n;
double fn(int x,int y,int z,int n) {
	if(x<0 || y<0 || z<0) {return 0;}
  	if(!x && !y && !z) {return 0;}
  	if(dp[x][y][z]>0) {return dp[x][y][z];}
  	int t=x+y+z;
  	return dp[x][y][z]=(n+x*fn(x-1,y,z,n)+y*fn(x+1,y-1,z,n)+z*fn(x,y+1,z-1,n))/t;
}
int main() {
  	int x=0,y=0,z=0,a;
  	cin>>n;
  	for(int i=0;i<n;i++) {
      cin>>a;
      x+=(a==1)?1:0;
      y+=(a==2)?1:0;
      z+=(a==3)?1:0;
    }
  	memset(dp,-1,sizeof(dp));
  	cout<<fixed<<setprecision(9);
  	double t=fn(x,y,z,n);
  	cout<<t<<endl;
return 0;
}
