#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;
int ara[N];
int main()
{
    IOS;
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    int ans=inf;
    for(int i=k;i<=n;i++)
    {
        if(ara[i]>0&&ara[i-k+1]<0){
            int sum=ara[i]-ara[i-k+1];
            int f1=sum+ara[i];
            int f2=sum-ara[i-k+1];
//            cout<<i<<" "<<f1<<" "<<f2<<endl;
            ans=min(ans,min(f1,f2));
        }
        else
        {
            int sum;
            if(ara[i]<0)sum=abs(ara[i-k+1]);
            else sum=ara[i];
            ans=min(ans,sum);

        }
    }
    cout<<ans<<endl;
}


/*
8 7
-10 -4 -2 0 5 6 8 13

8 5
-15 -12 -8 -7 -4 -1 8 15
*/



