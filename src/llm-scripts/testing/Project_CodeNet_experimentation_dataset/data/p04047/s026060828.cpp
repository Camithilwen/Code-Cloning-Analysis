#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
int main()
{
    fast;
    int n; cin>>n;
    int ans=0;
    vector<int> v;
    for(int i=0;i<2*n;i++)
    {
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto i=v.begin();i!=v.end();i=i+2)
    {
       // cout<<*i<<endl;
        ans+=*i;
    }
   cout<<ans<<endl;
}
