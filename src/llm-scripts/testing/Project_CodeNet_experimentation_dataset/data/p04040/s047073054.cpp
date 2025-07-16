#include <iostream>
using namespace std;
const long long MOD = 1e9+7;
//aのMODbでの逆元
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
long long combi(int n,int k){
    k = min(k,n-k);
    long long p = 1;
    for(int i = n;i>=n-k+1;i--){
        p*=i;
        p%=MOD;
    }
    for(int i = 0;i<k;i++){
        p*=modinv(i+1,MOD);
        p%=MOD;
    }
    return p;
}
int main(){
    long long h,w,a,b;
    cin >> h >> w >> a >> b;
    long long comb1 = 1;
    long long comb2 = combi(w+h-b-2,w-b-1);
    long long ans = 0;
    for(int i = 0;i<h-a;i++){
        ans+=((comb1*comb2)%MOD);
        ans%=MOD;
        comb1*=(b+i);
        comb2*=(h-1-i);
        comb1%=MOD;
        comb2%=MOD;
        comb1*=modinv(i+1,MOD);
        comb2*=modinv(w+h-b-2-i,MOD);
        comb1%=MOD;
        comb2%=MOD;
    }
    cout << ans << endl;
}