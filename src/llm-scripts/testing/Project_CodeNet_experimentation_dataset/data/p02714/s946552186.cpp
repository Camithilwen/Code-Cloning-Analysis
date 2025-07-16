/* You can't hack me! */
#include"bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define fo(i,n) for(ll i=0; i<(n); i++)
#define FO(i,a,b) for(auto i=a; i!=(b); i+=(b)>(a)?1:-1)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define os(x) cout<<x<<' '
#define on(x) cout<<x<<"\n"
#define nl cout<<"\n"
#define maxe(x) max_element(all(x))-(x).begin()
#define mine(x) min_element(all(x))-(x).begin()
const ll P=998244353;
const ll MaxN=2000010;
const long double pi=3.14159265358979323846264338;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\ASISH\\Desktop\\coding\\input.txt", "r", stdin);
    freopen("C:\\Users\\ASISH\\Desktop\\coding\\output.txt", "w", stdout);
#endif

    ll T=1;
    // cin>>T;
    fo(q, T)
    {
        ll N, ans=0;
        cin>>N;
        vll cnt(3);
        string s;
        cin>>s;
        for(auto x : s){
            if(x=='R') cnt[0]++;
            else if(x=='G') cnt[1]++;
            else cnt[2]++;
        }
        ans=cnt[0]*cnt[1]*cnt[2];
        // on(ans);
        fo(i, N-2){
            FO(k, i+2, N){
                // os(i); on(k);
                if((i+k)%2) continue;
                ll j=(i+k)/2;
                if(s[k]!=s[j] && s[j]!=s[i] && s[i]!=s[k]) ans--;
            }
        }
        on(ans);
    }
    cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "s\n";
    return 0;
}