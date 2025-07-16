#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}
const int MAXN = 4001;

int main(){
    int N;string S;cin >> N >> S;
    ll count = 0;
    ll red=0,blue=0,green=0;
    for(int i=0;i<N;i++){
        if(S[i]=='R')red++;
        if(S[i]=='B')blue++;
        if(S[i]=='G')green++;
        for(int k=0;k<N;k++){
            int tmp_i = i+1;int tmp_k = k+1;
            int tmp_j = (tmp_i+tmp_k)/2;
            int j = tmp_j - 1;
            if(tmp_j <= N && tmp_i< tmp_j && tmp_j<tmp_k && tmp_j - tmp_i == tmp_k - tmp_j  && S[i]!=S[j] && S[j] != S[k] && S[i] != S[k]){
                count++;
            }
        }
    }
    ll tmp = red*blue*green;
    
    cout << tmp - count << endl;




    return 0;

}