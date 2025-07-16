#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll Gcd(ll a,ll b){
    if(a < b)swap(a, b);

	if(a%b == 0)return(b);

	else return(Gcd(b, a%b));
}

vector<pll> Factor(ll n){
    vector<pll> prime;
    ll sq = sqrt(n) + 1;

    for(int i = 2; i <= sq; ++i){
        sq = sqrt(n) + 1;
        if(n%i == 0){
            prime.push_back(make_pair(i, 0));
            while(n%i == 0){
                n /= i;
                prime[prime.size()-1].second++;
            }
        }
    }

    if(n != 1){
        prime.push_back(make_pair(n, 1));
    }

    return prime;
}

int main(){
    ll a, b;
    cin >> a >> b;

    vector<pll> fac = Factor(Gcd(a, b));

    cout << fac.size() + 1 << endl;
}