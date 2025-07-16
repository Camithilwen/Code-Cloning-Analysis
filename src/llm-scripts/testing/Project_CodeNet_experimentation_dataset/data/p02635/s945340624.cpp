#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define PI acos(-1)
#define pb push_back
#define int long long
#define ld long double
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int M = 998244353;
const int N = 305;

int n,m,k;
vector<int> v,u;
vector<vector<int>> ans;
int dp[N][N][N];

int rec(int id,int carry,int can)
{
    if(id == -1)
    {
        //if(!carry){ans.pb(u);}
        return (carry == 0);
    }
    if(dp[id][carry][can] != -1)return dp[id][carry][can];
    int has = v[id] + carry;
    int ans = 0;
    for(int give=0;give<=min(has,k);give++)
    {
        int left = has - give;
        //u[id] = left;
        int now = max(0LL,left-v[id]);
        if(now > can)break;
        ans += rec(id-1,give,can-now),ans %= M;
    }
    dp[id][carry][can] = ans;
    return ans;
}

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int ii=0;ii<N;ii++)dp[i][j][ii]=-1;
        string s;
        cin>>s>>k;
        n = s.length();
        k = min(n,k);
        int curr = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                v.pb(curr);
                curr = 0;
            }
            else curr++;
        }
        if(curr)v.pb(curr);
        m = v.size();
        //u = v;
        cout<<rec(m-1,0,k)<<endl;
        //sort(all(ans));
        //for(auto u:ans){for(auto i:u)cout<<i<<" ";cout<<endl;}
    }
    return 0;
}
