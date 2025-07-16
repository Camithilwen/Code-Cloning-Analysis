#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long
#define MAX_N 200001

using namespace std;

long long MOD = 1000000007;

long long fact[MAX_N];
void factorial(int N){
    fact[0]=1;
    for(int i=0; i<N; i++){
        fact[i+1]=(i+1)*fact[i]%MOD;
    }
}

map<long long, long long> inv;
long long inverse(long long x){
    if (inv.count(x)){
        return inv[x];
    }
    long long p=MOD-2;
    long long ret=1;
    long long tmp=x;
    while(p>0){
        if(p%2==1)ret=ret*tmp%MOD;
        tmp=tmp*tmp%MOD;
        p/=2;
    }
    inv[x]=ret;
    return ret;
}

long long comb(int a, int b){
    long long ret=fact[a]*inverse(fact[a-b])%MOD;
    return ret*inverse(fact[b])%MOD;
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;

    factorial(200000);
    ll ans=0;
    for(ll y=0; y<N-1; y++){
        if(N*M-2<K-2)continue;
        ans+=((N+y)*(N-y-1)/2-y*(N-y-1))%MOD*M%MOD*M%MOD*comb(N*M-2,K-2)%MOD;
        ans%=MOD;
    }
    for(ll x=0; x<M-1; x++){
        if(M*N-2<K-2)continue;
        ans+=((M+x)*(M-x-1)/2-x*(M-x-1))%MOD*N%MOD*N%MOD*comb(M*N-2,K-2)%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
}