#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x,val) memset(x, val, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> ;
#define pal pair < ll, ll> ;
#define vi vector <int> ;
#define vl vector < ll > ;
#define vpai vector < pii > ;
#define prec(val,x) cout<<fixed<<setprecision(x)<<val;

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 305;
int n;

ll dp[sze][sze][sze];

ll calc(int one,int two,int three){
    if(one<0||two<0||three<0) return 0;
    if(one==0&&two==0&&three==0) return 0;
    if(dp[one][two][three]>0) return dp[one][two][three];
    int rem=one+two+three;
    ll exp=n+one*calc(one-1,two,three)+two*calc(one+1,two-1,three)+
            three*calc(one,two+1,three-1);
    return dp[one][two][three]=exp/rem;
}

void solve() {
    //int n;
    cin>>n;
    int arr[n];
    int x=0,y=0,z=0;
    rep(i,n) {
        cin>>arr[i];
        if(arr[i]==1) x++;
        if(arr[i]==2) y++;
        if(arr[i]==3) z++; 
    }
    prec(calc(x,y,z),14);
    cout<<endl;

}

int main() {
    IOS;

    int t = 1;
    //cin >> t;
    while (t--) {
        mem(dp,-1);
        solve();
    }

  return 0;
}