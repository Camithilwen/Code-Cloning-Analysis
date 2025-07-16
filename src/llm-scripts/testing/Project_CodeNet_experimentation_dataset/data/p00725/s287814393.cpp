#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INFTY=1<<29;

int dfs(vvi& a,int ci,int cj,int depth)
{
	if(depth==10)
		return INFTY;
	
	int h=a.size(),w=a[0].size();
	int di[]={-1,1,0,0},dj[]={0,0,-1,1};
	int res=INFTY;
	rep(k,4){
		for(int i=ci+di[k],j=cj+dj[k];;i+=di[k],j+=dj[k]){
			if(i<0 || h<=i || j<0 || w<=j)
				break;
			if(a[i][j]==1){
				if(abs(i-ci)+abs(j-cj)>1){
					a[i][j]=0;
					res=min(res,dfs(a,i-di[k],j-dj[k],depth+1));
					a[i][j]=1;
				}
				break;
			}
			if(a[i][j]==3)
				return depth+1;
		}
	}
	return res;
}

int main()
{
	for(int w,h;cin>>w>>h;){
		vvi a(h,vi(w));
		rep(i,h) rep(j,w)
			cin>>a[i][j];
		
		rep(i,h) rep(j,w)
			if(a[i][j]==2){
				a[i][j]=0;
				int res=dfs(a,i,j,0);
				cout<<(res==INFTY?-1:res)<<endl;
			}
	}
	
	return 0;
}