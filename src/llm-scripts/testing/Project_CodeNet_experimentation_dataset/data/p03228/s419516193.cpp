#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    ll a,b,k;
    cin>>a>>b>>k;
    bool t=1;
    while (k--)
    {
        if (t)
        {
            if (a&1)
                a--;
            b=b+a/2;
            a/=2;
            t=0;
        }
        else
        {
            if (b&1)
                b--;
            a=a+b/2;
            b/=2;
            t=1;
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
