#include <cstdio>
#include <iostream>

using namespace std ;

typedef long long ll ;

const int N = 300010 ;

int n ;
ll ans ;
ll S[4] ;
ll minx ;
ll maxx ;
ll sum[N] ;
ll base[N] ;

ll gt(ll x){
    return x < 0 ? -x : x ;
}
void chkmin(ll x){
    minx = x >= minx ? minx : x ;
}
void chkmax(ll x){
    maxx = x >= maxx ? x : maxx ;
}
int main(){
    cin >> n ;
    ans = (1ll << 62) ;
    for (int i = 1 ; i <= n ; ++ i){
        scanf("%lld", &base[i]) ;
        sum[i] = sum[i - 1] + base[i] ;
    }
    int l = 2, r = 4 ;
    S[0] = base[1] ; S[2] = base[3] ;
    S[1] = base[2] ; S[3] = sum[n] - sum[3] ;
    for (int i = 3 ; i <= n ; ++ i){
        while (l < i && gt(S[0] - S[1]) > gt(S[0] + base[l] - S[1] + base[l])){
            S[0] += base[l], S[1] -= base[l], ++ l ;
        }
        while (r <= n && gt(S[3] - S[2]) > gt(S[2] + base[r] - S[3] + base[r])){
            S[2] += base[r], S[3] -= base[r], ++ r ;
        }
        minx = (1ll << 61) ; maxx = -(1ll << 61) ;
        for (int j = 0 ; j <= 3 ; ++ j) chkmin(S[j]), chkmax(S[j]) ;
        ans = min(ans, maxx - minx) ; S[1] += base[i] ; S[2] -= base[i] ;
        //for (int j = 0 ; j <= 3 ; ++ j) cout << S[j] << " " ; puts("") ;
    }
    cout << ans << endl ; return 0 ;
}
