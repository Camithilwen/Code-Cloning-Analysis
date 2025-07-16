#include<bits/stdc++.h> 
using namespace std; 
#define int long long  

map<int, map<int, int> > dp1;
map<int, map<int, int> > dp2;
int mo=1000000007;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int x[n+5];
    int y[m+5];
    int dpx[n+5];
    int dpy[m+5];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int j=0;j<m;j++)
        cin>>y[j];
    sort(x,x+n);
    int mo=1000000007;
    int sx=0,sy=0;
    for(int i=1;i<n;i++)
        sx=(sx + (((((x[i]-x[i-1])*i)%mo)*(n-i))%mo) )%mo;
    sort(y,y+m);
    for(int i=1;i<m;i++)
        sy=(sy + (((((y[i]-y[i-1])*i)%mo)*(m-i))%mo) )%mo;

    //cout<<sx<<" "<<sy<<" ";
    cout<<(sx*sy)%mo;
}