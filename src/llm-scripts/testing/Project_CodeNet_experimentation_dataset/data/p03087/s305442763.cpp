/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;ll l[n+1];l[1]=0,l[0]=0;
    string s;
    cin>>s;
    for(int i=2;i<=n;i++){
        if(s[i-2]=='A'&&s[i-1]=='C')l[i]=l[i-1]+1;
        else l[i]=l[i-1];
    }
    for(int i=1;i<=q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<l[b]-l[a]<<endl;
    }
}
