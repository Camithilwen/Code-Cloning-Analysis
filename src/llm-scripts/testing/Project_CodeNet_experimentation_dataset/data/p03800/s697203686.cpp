#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define REP(i, N) for (long long i = 0; i < (N); i++)
#define FORR(i, a, b) for (long long i = (a); i >= (b); i--)
#define REPR(i, N) for (long long i = n; i >= 0; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define ALL(s) (s).begin(), (s).end()
#define pb(a) push_back(a)

#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

int main()
{
    ll N;
    string s;
    cin >> N;
    cin >> s;
    string ans;
    string init_pattern[4] = {"SS", "SW", "WS", "WW"};
    for(string p: init_pattern){
        ans = "";
        ans += p;
        FOR(i,2,N+2){
            if(s[(i-1)%N] == 'o'){
                if(ans[i-1] == 'S'){
                    ans += ans[i-2];   
                }else{
                    ans += (ans[i-2] == 'S') ? 'W' : 'S';
                }
            }else {
                if(ans[i-1] == 'S'){
                    ans += (ans[i-2] == 'S') ? 'W' : 'S';
                }else{
                    ans += ans[i-2]; 
                }
            }
        }
        if (ans[0] == ans[N] && ans[1] == ans[N+1]){
            break;
        }
        ans = "-1";
    }
    cout << ans.substr(0,N) << endl;
}
