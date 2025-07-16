#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

int main()
{
    fastread();

    ll n,m;

    cin>>n>>m;
    ll a,b;
    cin>>a>>b;


    for(ll i=0;i<m-1;i++)
    {
        ll a1,b1;

        cin>>a1>>b1;

        a=max(a,a1);
        b=min(b,b1);
    }

    cout<<max(b-a+1,0ll)<<endl;


}
