#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0LL;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define F first
#define S second
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);


void solve()
{
    string v[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string s;
    cin >> s;
    int i;
    rep(i,7)
    {
        if(v[i]==s)
        {
            cout << 7-i ;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
   // cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
