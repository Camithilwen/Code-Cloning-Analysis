#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uu unsigned
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define pl pair<ll,ll>
#define mkp make_pair
#define ss second
#define ff first
#define mit(a,b) map<a,b>::iterator
#define sit(a) set<a>::iterator
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define printcas cout<<"Case "<<cas<<": "
#define _ continue;
#define endl '\n'
#define __ cout<<endl;continue;
#define dd (double)
const ll oo=(1ll<<60);
int gi(){
	int x=0,w=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')w=0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
double dp[305][305][305]={0};
int main()
{
     //io;
    //string hudai(1000000,'a');
    int T=1;
    //T=gi();
     for(int cas=1;cas<=T;cas++)
    {
        int n,x,cnt[4]={0},i,j,k;
        n=gi();
        for(i=0;i<n;i++)
        {
            x=gi();
            cnt[x]++;
        }
        dp[0][0][0]=0.0;
        for(i=0;i<=cnt[3];i++)
        {
            for(j=0;j<=cnt[2]+cnt[3];j++)
            {
                for(k=0;k<=cnt[1]+cnt[2]+cnt[3];k++)
                {
                    if(i+j+k==0) _
                    dp[i][j][k]=(1.0/(i+j+k+0.0))*(n+0.0+((!i)?0.0:i*1.0*dp[i-1][j+1][k])+((!j)?0.0:j*1.0*dp[i][j-1][k+1])+((!k)?0.0:k*1.0*dp[i][j][k-1]));
                    //if(dp[i][j][k]-n==0.0) cout<<i<<' '<<j<<' '<<k<<endl;
                }
            }
        }
        printf("%.15lf",dp[cnt[3]][cnt[2]][cnt[1]]);


    }
    return 0;
}
