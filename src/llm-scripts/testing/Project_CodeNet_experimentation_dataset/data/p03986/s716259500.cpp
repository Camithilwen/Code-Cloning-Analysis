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

int main()
{
    IOS;
    string s;cin>>s;
    int n=s.length();
    int cnt=0;
    int i=0;
    int ss=0,t=0;
    while(i<n)
    {
//        cout<<"i = "<<i<<endl;
        while(s[i]=='S'){
            ss++,i++;
            if(i==n)break;
        }
        while(s[i]=='T'){
            i++,t++;
            if(i==n)break;
        }
        cnt+=min(ss,t);
        ss=max(ss-t,0);
        t=0;
    }
    cout<<n-cnt*2<<endl;
}
/*
sttssttsst
SSSSTTSSTTTS
*/





