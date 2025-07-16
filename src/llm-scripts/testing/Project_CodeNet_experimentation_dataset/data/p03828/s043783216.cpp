#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

bool prime[1001];

void sieve(){

    memset(prime,false,sizeof(prime));
    for(int i=2;i<=1000;i++){
        if(!prime[i]){
            for(int j=i*i;j<=1000;j=j+i){
                prime[j]=true;
            }
        }
    }
}

int32_t main()
{   
    sieve();
    int n;cin>>n;

    vi v(1000,0);
    for(int k=2;k<=n;k++){
        for(int i=2;i<=n;i++){
            if(!prime[i]){
                int cnt=0,val=k;
                while(val%i==0){
                    v[i]++;
                    val=val/i;
                }
                // cout<<"I inserted something"<<endl;
            }
        }
    }

    int ans=1;
    for(auto x:v){
        ans*=(x+1);
        ans%=mod;
    }
    cout<<endl;
    cout<<ans%mod<<endl;
    return 0;
}