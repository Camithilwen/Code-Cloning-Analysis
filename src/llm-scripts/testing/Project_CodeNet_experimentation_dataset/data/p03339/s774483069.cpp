#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,w;
ll direction2[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
bool valid(int a,int b)
{
    if(a>=1&&a<=h&&b>=1&&b<=w)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x=1000000;
    cin>>n;
    unordered_map<ll,ll>nw,ne;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='W')nw[i]=1+nw[i-1];
        else nw[i]=nw[i-1];
        if(s[n-i-1]=='E')ne[n-i-1]=1+ne[n-i];
        else ne[n-i-1]=ne[n-i];
    }
    for(int i=0;i<n;i++){
        x=min(x,(nw[i-1]+ne[i+1]));
        //cout<<nw[i-1]<<" "<<ne[i+1]<<endl;
    }
    cout<<x;
}
