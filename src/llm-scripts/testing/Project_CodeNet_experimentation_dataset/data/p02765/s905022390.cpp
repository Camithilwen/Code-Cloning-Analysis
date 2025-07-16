#include <bits/stdc++.h>

#define int long long
#define fast_io(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second
#define _max max_element
#define _min min_element
#define tc(T) int T; cin>>T; while(T--)
#define q(q) int q; cin>>q; while(q--)
#define pi 3.1415926535897932384626433832
const int pinf=((int)9e18);
const int ninf=((int)-9e18);
const int mod=1000000007;

using namespace std;

int32_t main()
{
    fast_io();

    //FILE *fptr1=freopen("in.txt","r",stdin);
    //FILE *fptr2=freopen("out.txt","w",stdout);

    int n,r;
    cin>>n>>r;

    if(n>=10)
    {
        cout<<r;
    }
    else
    {
        cout<<r+100*(10-n);
    }


    return 0;
}
