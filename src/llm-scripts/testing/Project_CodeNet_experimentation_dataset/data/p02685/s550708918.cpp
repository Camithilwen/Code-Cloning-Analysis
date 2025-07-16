#include <bits/stdc++.h>
#define simplify ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl "\n"
using namespace std;

const int mod=998244353;
const int N=2e5+5;

int fact[N];
int invFact[N];

int inverseMod(int x,int mod);
void precompute(){
    fact[0]=fact[1]=1;

    for(int i=2;i<N;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    invFact[N-1]=inverseMod(fact[N-1],mod);

    for(int i=N-2;i>=0;i--){
        invFact[i]=invFact[i+1]*(i+1);
        invFact[i]%=mod;
    }
}
int NCR(int n,int r){

    if(r>n)return 0;
    int num=fact[n];
    num*=invFact[r];
    num%=mod;
    num*=invFact[n-r];
    num%=mod;
    return num;
}



int power(int x,int n,int mod){
//(x^n)%mod
    int result=1;
    while(n){
        if(n%2)
            result=(result*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return result;
}

int inverseMod(int x,int mod){

return power(x,mod-2,mod);
}




int32_t main(){

    simplify
    int n,m,k;
    cin>>n>>m>>k;
    precompute();
    int ans=0;
    int other;
    for(int i=0;i<=k;i++){
        other=m*power(m-1,n-1-i,mod);
        other%=mod;
        other=other*NCR(n-1,i);
        other%=mod;
        ans+=other;
        ans%=mod;
    }
    cout<<ans;




    
    return 0;
}






