#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    int n,k; cin >> n >> k;
    int a[n];
    rep(i,n) cin >> a[i];
    int tmp[n];
    
    for(int t = 0; t < k; t++){
        rep(i,n) tmp[i] = 0;
        rep(i,n){
            if(i - a[i] < 0){
                tmp[0]++; 
            }else{
                tmp[i-a[i]]++;
            }
            if(i + 1 + a[i] < n){
                tmp[i+1+a[i]]--;
            }
        }
        a[0] = tmp[0];
        rep(i,n-1){
            a[i+1] = a[i] + tmp[i+1];
        }
        bool f = true;
        rep(i,n) if(a[i] != n) f = false;
        if(f) break;
    }
    rep(i,n) cout << a[i] << ' ';
}