#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)
struct str{
    int ax,ay,bx,by;
};
int main()
{
    fast;
    int h,w;
    cin>>h>>w;
    vector<str>ans;
    int a[h+5][w+5];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
           cin>>a[i][j];

        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w-1;j++)
        {
            if(a[i][j]&1)
            {
                a[i][j+1]++;
                ans.pb({i+1,j+1,i+1,j+2});
            }
            else continue;
        }
        if(i==h-1)continue;
        if(a[i][w-1]&1)
        {
            a[i+1][w-1]++;
            ans.pb({i+1,w,i+2,w});
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i.ax<<" "<<i.ay<<" "<<i.bx<<" "<<i.by<<endl;
    }
}

