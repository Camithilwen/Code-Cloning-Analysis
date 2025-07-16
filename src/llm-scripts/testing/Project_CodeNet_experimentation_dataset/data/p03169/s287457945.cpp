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
const ll oo=(1ll<<60);
int gi(){
	int x=0,w=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')w=0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
vector<vector<vector<double>>> dp(305,vector<vector<double>>(305,vector<double>(305,-1.0)));
double n;
double e(double t1,double t2,double t3)
{
    if(dp[(int)t1][(int)t2][(int)t3]!=-1) return dp[(int)t1][(int)t2][(int)t3];
    return dp[(int)t1][(int)t2][(int)t3]=(1.0/(t1+t2+t3))*(n+((!t1)?0:(t1*e(t1-1.0,t2,t3)))+((!t2)?0:(t2*e(t1+1.0,t2-1.0,t3)))+((!t3)?0:(t3*e(t1,t2+1.0,t3-1.0))));
}
int main()
{
     //io;
    //string hudai(1000000,'a');
    int T=1;
    //T=gi();
     for(int cas=1;cas<=T;cas++)
    {
        double t1=0.0,t2=0.0,t3=0.0,x;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>x;
           if(x==1)t1+=1.0;
           else if(x==2) t2+=1.0;
           else t3+=1.0;
       }
//       int mx=max(t1,max(t2,t3));
//       for(int i=0;i<=n+2;i++)for(int j=0;j<=n+2;j++)for(int k=0;k<=n+2;k++)dp[i][j][k]=-1;
       dp[0][0][0]=0;
       printf("%.15lf",e(t1,t2,t3));

    }
    return 0;
}
