#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,t,sum=0,en=-1,last;
    cin>>n>>t;
    while(n--)
    {
        ll a;
        cin>>a;
        if(a>en)
        {
            sum+=t;
            en=a+t;
            last=a;
        }
        else{
            sum+=(a-last);
            en=a+t;
            last=a;
        }
    }
    cout<<sum<<endl;
    return 0;
}
