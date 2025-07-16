#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<ll> num(1010,0); 
vector<bool> prime(1010,true);//iが素数ならtrue(エラトステネスの篩)
void isprime(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i*i<=1010;i++){
        if(!prime[i]){continue;}
        for(ll j=i*i;j<=1010;j+=i){
            prime[j]=false;
        }
    }
    return;
}

int main(){
    ll n;cin>>n;
    isprime();

    if(n==1){cout<<1<<endl;return 0;}

    for(ll i=2;i<=n;i++){//n以下の連続整数の素因数個数を数える
        ll number=i;
        for(ll j=2;j<=i;j++){
            if(prime[j]==true){
                while(number%j==0){
                    num[j]++;
                    number/=j;
                }
            }
        }
    }

    ll ans=1;
    for(ll i=2;i<=n;i++){//約数個数を計算
        ans*=(num[i]+1);
        ans%=mod;
    }

    cout<<ans<<endl;

    return 0;
}