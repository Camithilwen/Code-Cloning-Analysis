#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plii pair<ll,pii>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define lw(vc,num) lower_bound(vc.begin(), vc.end(), num) - vc.begin();
#define hg(vc,num) upper_bound(vc.begin(), vc.end(), num) - vc.begin();
#define bn(v,x) binary_search (v.begin(), v.end(), x)
#define mx 100001
#define eps 0.00000000001
#define mod 1000000007
#define pi acos(-1)
#define inf 100000000
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool isprime(int n)
{
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<=n; i+=6){
        if((n%i == 0)||(n%(i+2) == 0)) return false;
    }
    return true;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int main()
{
    fio;
    int n;
    cin>>n;
  vi v1(n);
    loop(i,0,n)
    {
        cin>>v1[i];
    }
    int ans = 0,k1 = INT_MAX;
    loop(i,0,n)
    {
       if(k1>v1[i])
       {
           k1 = v1[i];
           ans++;
       }
    }
    cout<<ans<<endl;
    return 0;
}

