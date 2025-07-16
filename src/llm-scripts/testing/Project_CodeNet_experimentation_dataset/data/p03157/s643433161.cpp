/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int h,w;
string s[440];
bool vis[440][440]={false};
int typ[2];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
void dfs(int i, int j)
{
	vis[i][j]=true;
	if(s[i][j]=='#')
		++typ[0];
	else
		++typ[1];
	for(int k=0;k<4;++k)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(x>=0&&x<h&&y>=0&&y<w&&vis[x][y]==false&&s[i][j]!=s[x][y])
			dfs(x,y);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli res=0ll;
    cin>>h>>w;
    for(int i=0;i<h;++i)
    	cin>>s[i];
    for(int i=0;i<h;++i)
    	for(int j=0;j<w;++j)
    	{
    		if(vis[i][j])
    			continue;
    		if(s[i][j]=='.')
    			continue;
    		typ[0]=0;
    		typ[1]=0;
    		dfs(i,j);
    		res+=1ll*typ[0]*typ[1];
    	}
    cout<<res<<endl;
}