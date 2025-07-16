#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INT = 1e9;
const ll LINF = 1e18;

struct UF{
    vector<int> d;
    UF(int size):d(size,-1){}
    bool u(int x,int y){
        x = r(x); y = r(y);
        if(x != y){
            if(d[y] < d[x]) swap(x,y);
            d[x] += d[y]; d[y] = x;
        }
        return x!=y;
    }
    bool f(int x,int y){
        return r(x) == r(y);
    }
    int r(int x){
        return d[x] < 0 ? x:d[x] = r(d[x]);
    }
    int s(int x){
        return -d[r(x)];
    }
};

//const ll MAX_PRIME = 200000;
//vector<int> primes;
//vector<int> is_prime(MAX_PRIME + 1,true);
//void init_primes(){
//    is_prime[0] = is_prime[1] = false;
//    for(int i = 2; i <= MAX_PRIME;i++){
//        if(is_prime[i]){
//            primes.push_back(i);
//            for(int j = i*2;j<=MAX_PRIME;j+=i) is_prime[j] = false;
//        }
//    }
//}
//void solveF(){
//    init_primes();
//    ll N,P;
//    vector<ll> sum;
//    while(cin >> N >> P){
//        if(N == -1 && P == -1) break;
//        sum.clear();
//        auto idx = upper_bound(primes.begin(),primes.end(),N) - primes.begin();
//        for(int i = 0; i <= P;i++){
//            for(int j = i; j <= P;j++){
//                ll S = primes[idx+i] + primes[idx+j];
//                sum.push_back(S);
//            }
//        }
//        sort(sum.begin(),sum.end());
//        cout << sum[P-1] << endl;
//    }
//}


double func(ll P,ll A,ll B,ll C,ll D,ll E,ll F,ll S,ll M){
    double ret = 0;
    ll sum = M*F*S;
    ll kouritu = sum - P;
    ll T = A + B + C + D + E + (D + E)*(M-1);
    ret = kouritu/(double)T;
    return ret;
}
void solveG(){
    int N;
    while(cin >> N,N){
        vector<pair<double,string>> ans(N);
        for(int i = 0; i < N;i++){
            string L; cin >> L;
            ll P,A,B,C,D,E,F,S,M; cin >> P >> A >> B >> C >> D >> E >> F >> S >> M;
            ans[i] = {pair<double,string>{-func(P,A,B,C,D,E,F,S,M),L}};
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i < N;i++){
            cout << ans[i].second << endl;
        }
        cout << "#" << endl;
    }
}
int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    //solveF();
    solveG();
    return 0;
}

