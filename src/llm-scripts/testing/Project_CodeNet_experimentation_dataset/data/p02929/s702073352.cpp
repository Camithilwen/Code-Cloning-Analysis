#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 200005
int n;
string s;
bool op[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    F0R(i, 2*n){
        if(s[i] == 'B'){
            op[i] = (i+1)%2;
        } else{
            op[i] = i%2;
        }
        //cout << op[i] << " ";
    }
    //cout << "\n";
    ll amt = 1;
    int cnt = 0;
    F0R(i, 2*n){
        if(op[i]) ++cnt;
        else{
            amt = (amt*cnt)%MOD;
            --cnt;
        }
        if(cnt < 0){
            cout << "0\n";
            return 0;
        }
    }
    if(cnt != 0){
        cout << "0\n";
        return 0;
    }
    FOR(i, 1, n) amt = (amt*i)%MOD;
    cout << amt << "\n";

    return 0;
}
