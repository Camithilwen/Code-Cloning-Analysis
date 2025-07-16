#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int H,W,A,B; cin>>H>>W>>A>>B;
    
    rep(i,H){
        rep(j,W){
            cout << (((i<B)^(j<A))?1:0);
        }
        cout << endl;
    }
    return 0;
}