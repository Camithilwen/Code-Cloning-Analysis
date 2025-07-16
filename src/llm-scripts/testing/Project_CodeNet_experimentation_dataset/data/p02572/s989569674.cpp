#include <bits/stdc++.h>
#define iso ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int main()
{ iso
    unsigned ll n,s=0,w=0;
    cin>>n;
    vector<unsigned ll>vec;
    while(n--)
    {
        ll x;
        cin>>x;
        vec.push_back(x);
        s+=x;
    }

    for(int i=0;i<vec.size();i++)
    {
        s-=vec[i];
        w+=s%1000000007*vec[i]%1000000007;
        w%=1000000007;
    }
    cout<<w<<"\n";

    return 0;
}
