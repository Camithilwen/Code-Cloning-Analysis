///*Bismillahir Rahmanir Rahim***///
/***Stay_Home_Stay_Safe***/
///**Author Thasin Sheikh**///
#include<bits/stdc++.h>
using namespace std;
#define MAX 35000
#define MOD 1000000007
#define PI 3.14159265359
#define makefast__  ios_base::sync_with_stdio(false);
using ll=long long int  ;
using dl =double;
const int N = 2e5 + 10;
ll aarray[300000+10];
ll magic[101][101];
vector<ll>primes;
bool prime[1000001];
ll chkbit(ll n,ll k)
{
    return n&(1LL<<k);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    makefast__
    string str;
    ll a,b,c,d,e,f,x,y,k,t,A=0,mod,B=0,L,j,i,l,r,m,n,C=0,ans=0,sum=0,sum1=0;
    vector<ll>v,v1;
    queue<ll>qu;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>aarray[i];
    for(i=0; i<64; i++)
    {
        ll cnt=0;
        for(j=0; j<n; j++)
        {
            if(chkbit(aarray[j],i))
                cnt++;
        }
        ll ad=((cnt*(n-cnt))%MOD)*((1LL<<i)%MOD);
        ans=(ans+ad)%MOD;

    }
    cout<<ans<<endl;


    return 0;
}