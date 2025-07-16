/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*                                                               *-*
*-*                  Bismillahir Rahmanir Rahim                   *-*
*-*                                                               *-*
*-*                  Author: Ahsan Habib (comrade)                *-*
*-*                    Metropolitan University                    *-*
*-*                         Language: C++                         *-*
*-*                                                               *-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
#include<bits/stdc++.h>
#include<istream>
#include<cstdio>
#define pii          pair<ll,ll >
#include<string>
#define In freopen("ahsan.txt","r",stdin);
#define ll long long
#define ff first
#define ss second
#define NO cout<<"NO"<<endl
#define m1 cout<<"-1"<<endl
#define No cout<<"No"<<endl
#define cinarr0(n) for(int i = 0;i<n;i++)cin>>a[i];
#define cinarr1(n) for(int i = 1;i<=n;i++)cin>>a[i];
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define pb push_back
#define sorta(a) sort(a,a+n)
#define sortv(v)  sort(v.begin,v.end())
#define bug(a) cerr << #a << " : " << a << endl
#define all(v) (v.begin(), v.end())
#define   sz(x)       x.size()
#define fill(x, y) memset(x, y, sizeof(x))
const int mx = 1e6+5;
const ll md = 1e9+7;
using namespace std;
ll a[200010],m,ans,i,t,k,ev=0,od=0,tt=0,n,cas = 1;
vector<int>vec[mx];
int ar[10000][10000];
vector<pii>v;
bool ok = true;
int main()
{
    //In;
  ///  ios::sync_with_stdio(false);
    ///cin.tie(0);
    ll   n,tot  = 0;

    cin>>n;
    vector<ll>a(n);
    ll ans = 0;
    int md = 1000000007;
    for(int i = 0 ; i <n; i++)
    {
        cin>>a[i];
        tot  = tot + a[i];
        tot = tot % md;
    }


    for(int i = 0 ; i <n; i++)
    {
         tot = tot - a[i];
         if(tot<0)tot+=md;
         ans = ans + a[i]*tot;
         //bug(ans);
         ans = ans%md;
    }
    cout<<ans<<endl;

    return 0;
}
