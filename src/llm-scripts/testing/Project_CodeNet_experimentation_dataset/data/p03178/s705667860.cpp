#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int d;
string s;
int dp[10005][101][2];

int f(int idx,int cur,bool gr)
{
    if(idx==s.size())
    {
        return (!cur);
    }
    int &ret=dp[idx][cur][gr];
    if(ret!=-1)
        return ret;
    ret=0;
    if(!gr)
    {
        for(int i=0; i<s[idx]-'0'; i++)
        {
            ret+=f(idx+1,(cur+i)%d,1);
            ret%=MOD;
        }
        ret+=f(idx+1,(cur+(s[idx]-'0'))%d,0);
        ret%=MOD;
    }
    else{
        for(int i=0;i<=9;i++){
            ret+=f(idx+1,(cur+i)%d,1);
            ret%=MOD;
        }
    }
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>s>>d;
        memset(dp,-1,sizeof dp);
        cout<<(f(0,0,0)+MOD-1)%MOD<<endl;
    }
    return 0;
}
