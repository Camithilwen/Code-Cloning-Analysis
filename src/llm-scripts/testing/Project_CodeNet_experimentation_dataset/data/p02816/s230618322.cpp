#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

vi LPS(vi pat)
{

    vi lps(sz(pat));
    lps[0]=0;
    ll len=0;
    ll i=1;
    while(i<sz(pat))
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len)
                len=lps[len-1];
            else
                lps[i]=0,i++;
        }
    }
    return lps;
}

vi KMP(vi pat,vi txt)
{
    vi lps=LPS(pat);
    vi ans;
    ll i=0,j=0;
    while(i<sz(txt))
    {
        if(pat[j]==txt[i]) i++,j++;
        if(j==sz(pat)) 
        {
            ans.pb(i-j+1);
            j=lps[j-1];
        }
        else if(i<sz(txt)&&txt[i]!=pat[j])
        {
            if(j)
                j=lps[j-1];
            else
                i++;
        }
    }
    return ans;
}
void solve()
{
    ll n,x;
    cin>>n;
    vi a;
    vi b;
    rep(i,0,n)
    {
        cin>>x;
        a.pb(x);
    }
    rep(i,0,n)
    {
        cin>>x;
        b.pb(x);
    }
    vi A,B;
    rep(i,0,n)
    {
        A.pb(a[i]^(a[(i+1)%n]));
        B.pb(b[i]^(b[(i+1)%n]));
    }
    rep(i,0,n-1)
    {
        A.pb(A[i]);
    }
    // cout<<KMP(B,A)<<endl;
    vi ans=KMP(B,A);
    for(auto u:ans)
    {
        cout<<u-1<<" "<<(a[u-1]^b[0])<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}