#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    ll N,M;
    cin >> N >> M;
    ll gcm = 0;
    if(N <= 10){
        for(ll i = N;;i++){
            if(M < i)break;
            if(M % i == 0){
                chmax(gcm,M/i);
                break;
            }
        }
    }else{
        for(ll i = 1;;i++){
            ll test = M - i*(N-1);
            if(test <= 0)break;
            if(test < i)break;
            if(test % i == 0){
                chmax(gcm,i);
            }
        }
    }
    cout << gcm << "\n";
}