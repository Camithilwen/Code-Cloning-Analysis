#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    long double N,M,D;
    cin >> N >> M >> D;
    if(D==0){
        cout << setprecision(10) << (1/N)*(M-1) << endl;
    }else{
        // 1組の隣り合った項の差がDである確率は
        // 2(N-D)通り / N*N通り
        cout << setprecision(10) << 2*(M-1)*(N-D)/N/N << endl;
    }
    return 0;
}