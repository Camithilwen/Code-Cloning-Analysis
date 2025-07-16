#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;


int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> X(N);
    int res = 0;
    REP(i, N){
        if (S[i] == 'W'){
            res++;
        }
        X[i] += res;
    }
    res = 0;
    REPD(i, N){
        if (S[i] == 'E'){
            res++;
        }
        X[i] += res;
    }

    int ans = MIN(X);

    cout << ans-1 << endl;
}