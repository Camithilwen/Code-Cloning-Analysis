#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    string S;
    cin >> S;

    char sign[2] = {'-', '+'};
    bool f = false;
    for(ll i=-1; i<2; i+=2) {
        for(ll j=-1; j<2; j+=2) {
            for(ll k=-1; k<2; k+=2) {
                if((S[0]-'0')+i*(S[1]-'0')+j*(S[2]-'0')+k*(S[3]-'0')==7) {
                    cout << S[0] << sign[(i+1)/2] << S[1] << sign[(j+1)/2] << S[2] << sign[(k+1)/2] << S[3] << "=7" << endl;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(f) break;
    }

    return 0;
}

/*



*/