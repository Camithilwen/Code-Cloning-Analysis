#include<bits/stdc++.h>
#define ll long long
#define dl double
#define mp make_pair
#define pb push_back
using namespace std;

//***********************************************************************

// hash struct for unordered_map
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int MAXNUM = 5e3+5;
vector <int>vis(MAXNUM);
vector<int> pr;
void sieve() {
	pr.push_back(2);
	for(ll i=3;i<MAXNUM;i+=2) if(!vis[i]) {
		pr.push_back(i);
		for(ll j=i*i;j<MAXNUM;j+=2*i) vis[j]=true;
	}
}
//************************************************************************

ll cnt[1<<16];
ll dp[1<<16];
// ll finddpvalue(ll mask,ll pos)
// {
//     if(pos==-1)
//     {
//         return cnt[mask];
//     }
//     if(dp[mask][pos]!=-1)
//     {
//         return dp[mask][pos];
//     }
//     ll ans=0;
//     ans+=finddpvalue(mask,pos-1);
//     if(mask&(1<<pos))
//     ans+=finddpvalue(mask^(1<<pos),pos-1);
//     return dp[mask][pos]=ans;

// }

ll finddpvalue2(int mask)
{
    if(mask==0)
    return 0;
    if(dp[mask]!=-1)
    return dp[mask];
    ll ans=cnt[mask];
    for(int i = (mask-1)&mask; i > 0; i = (i-1) & mask)
    {
        int group=mask^i;
        //cout << "mask : " << mask << " i : " << i << " grp :" << group << endl;
        ans=max(ans,cnt[group]+finddpvalue2(i));
    }
    return dp[mask]=ans;
}


void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n,vector<ll>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> v[i][j];
        }
    }
    memset(cnt,0,sizeof cnt);
    for(ll mask=0;mask<(1<<n);mask++)
    {
        for(ll i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                for(ll j=i+1;j<n;j++)
                {
                    if(mask&(1<<j))
                    cnt[mask]+=v[i][j];
                }
            }
        }
    }
    memset(dp,-1,sizeof dp);
    //cout << "c0"  << endl;
    ll ans=finddpvalue2((1<<n)-1);
    //cout << "c0"  << endl;
    cout << ans << endl;
}


int main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll t;
	//cin >> t;
	t=1;
	while(t--)
	{
		solve();
	}

	return 0;
}