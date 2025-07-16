#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int h,w;
int ex,ey;
short dp[101][101][101][101];
char a[101][101];
short S[101][101];

short calc(int r1, int r2, int c1, int c2)
{
	if(r1>r2||c1>c2) return 0;
	int ans = S[r2][c2];
	if(r1>0&&c1>0) ans+=S[r1-1][c1-1];
	if(r1>0) ans-=S[r1-1][c2];
	if(c1>0) ans-=S[r2][c1-1];
	return ans;
}

bool valid(int u, int d, int l, int r)
{
	if(u>ex||d>h-1-ex||l>ey||r>w-1-ey) return false;
	return true;
}

void amax(short &x, short y)
{
	if(y>x) x=y;
}

void update(int u, int d, int l, int r)
{
	int val = dp[u][d][l][r];
	//cerr<<u<<' '<<d<<' '<<l<<' '<<r<<' '<<val<<'\n';
	if(valid(u+1,d,l,r))
	{
		int L = r; int R = w - l - 1;
		int U = d; int D = h - (u + 1) - 1;
		amax(dp[u+1][d][l][r], val + calc(max(U,ex-u-1),min(D,ex-u-1),max(L,ey-l),min(R,ey+r)));
	}
	if(valid(u,d+1,l,r))
	{
		int L = r; int R = w - l - 1;
		int U = d + 1; int D = h - (u) - 1;
		amax(dp[u][d+1][l][r], val + calc(max(U,ex+d+1),min(D,ex+d+1),max(L,ey-l),min(R,ey+r)));
	}
	if(valid(u,d,l+1,r))
	{
		int L = r; int R = w - (l+1) - 1;
		int U = d; int D = h - u - 1;
		amax(dp[u][d][l+1][r], val + calc(max(U,ex-u),min(D,ex+d),max(L,ey-l-1),min(R,ey-l-1)));
	}
	if(valid(u,d,l,r+1))
	{
		int L = r+1; int R = w - l - 1;
		int U = d; int D = h - u - 1;
		amax(dp[u][d][l][r+1], val + calc(max(U,ex-u),min(D,ex+d),max(L,ey+r+1),min(R,ey+r+1)));
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='o') S[i][j]=1;
			if(i>0) S[i][j]+=S[i-1][j];
			if(j>0) S[i][j]+=S[i][j-1];
			if(i>0&&j>0) S[i][j]-=S[i-1][j-1];
			if(a[i][j]=='E') ex=i,ey=j;
		}
	}
	dp[0][0][0][0]=0;
	for(int sum = 0; sum <= h+w; sum++)
	{
		for(int u = 0; u <= min(ex,sum); u++)
		{
			for(int d = 0; d+u<=sum&&d<=h-1-ex; d++)
			{
				for(int l = 0; l<=ey&&d+u+l<=sum; l++)
				{
					int r = sum-u-d-l;
					if(r>=0&&r<=w-1-ey)
					{
						update(u,d,l,r);
					}
				}
			}
		}
	}
	cout<<dp[ex][h-1-ex][ey][w-1-ey]<<'\n';
}
