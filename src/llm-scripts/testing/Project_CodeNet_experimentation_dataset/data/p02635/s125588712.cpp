#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=310,MOD=998244353;

int dp[N][N][N];
int xxm[N][N][N];
int xmp[N][N][N];

#define get(arr)                    \
int get_##arr(int pos,int mov,int dif) \
{                                    \
    if(pos>=0&&mov>=0&&dif>=0)       \
        return arr[pos][mov][dif];   \
    else                             \
        return 0;                    \
}
get(dp)
get(xxm)
get(xmp)

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin>>s>>k;
    k=min<int>(k,s.size());
    vector<int> v{0};
    int cur=0;
    for(char c:s)
        if(c=='0')
            v.push_back(cur),
            cur=0;
        else
            cur++;
    v.push_back(cur);
    int n=v.size()-1;
//    cout<<n<<"\n";
//    for(int i=1;i<=n;i++)
//        cout<<v[i]<<" ";
//    cout<<"\n";
    dp[0][0][0]=1;
    xxm[0][0][0]=1;
    xmp[0][0][0]=1;
    for(int pos=0;pos<=n;pos++)
        for(int mov=0;mov<=k;mov++)
            for(int dif=0;dif<=k;dif++)
            {
                dp[pos][mov][dif]=(get_dp(pos,mov,dif)+
                                   get_xxm(pos-1,mov,dif-1)+
                                   get_xmp(pos-1,mov-1,dif+1)-
                                   get_xmp(pos-1,mov-1-v[pos],dif+1+v[pos])+
                                   get_dp(pos-1,mov,dif))%MOD;
                xxm[pos][mov][dif]=(dp[pos][mov][dif]+get_xxm(pos,mov,dif-1))%MOD;
                xmp[pos][mov][dif]=(dp[pos][mov][dif]+get_xmp(pos,mov-1,dif+1))%MOD;
//                cout<<pos<<" "<<mov<<" "<<dif<<" -> "<<dp[pos][mov][dif]<<"\n";
            }
    int ans=0;
    for(int mov=0;mov<=k;mov++)
        ans=(ans+dp[n][mov][0])%MOD;
    cout<<(ans+MOD)%MOD;
}
