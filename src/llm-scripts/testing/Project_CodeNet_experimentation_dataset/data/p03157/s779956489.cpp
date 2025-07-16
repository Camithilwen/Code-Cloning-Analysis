#include <bits/stdc++.h>
using namespace std;
template <class T> T input() {T t; cin>>t; return t;}
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define CHMAX(a,b) a = max(a,b)
#define CHMIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define PRINT_ARRAY_H(i,a) REPALL(i,a) {cout<<a[i]<<(i != a.size()-1 ? " " : "");} newline;
#define e1 first
#define e2 second
#define newline putchar('\n')
#define cspace ' '
#define sspace " "
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;
const VI dx = {1, 0, -1, 0};
const VI dy = {0, 1, 0, -1};

int H, W;
vector<string> s;
ll ans = 0ll;
VVI visited(444, VI(444));

ll bfs(int y, int x)
{
    int num_b = 1, num_w = 0;

    deque<pair<int, int>> frends;
    frends.push_back(make_pair(y, x));
    visited[y][x] = 1;

    while (!frends.empty()) {
        auto p = frends.front();
        frends.pop_front();

        if (s[p.e1][p.e2] == '#') {
            REP(i,4) {
                if (0 <= p.e2 + dx[i] && p.e2 + dx[i] < W && 0 <= p.e1 + dy[i] && p.e1 + dy[i] < H
                    && visited[p.e1 + dy[i]][p.e2 + dx[i]] == 0 && s[p.e1 + dy[i]][p.e2 + dx[i]] == '.') {

                    frends.push_back(make_pair(p.e1 + dy[i], p.e2 + dx[i]));
                    visited[p.e1 + dy[i]][p.e2 + dx[i]] = 1;
                    num_w++;
                }
            }
        } else if (s[p.e1][p.e2] == '.') {
            REP(i,4) {
                if (0 <= p.e2 + dx[i] && p.e2 + dx[i] < W && 0 <= p.e1 + dy[i] && p.e1 + dy[i] < H
                    && visited[p.e1 + dy[i]][p.e2 + dx[i]] == 0 && s[p.e1 + dy[i]][p.e2 + dx[i]] == '#') {

                    frends.push_back(make_pair(p.e1 + dy[i], p.e2 + dx[i]));
                    visited[p.e1 + dy[i]][p.e2 + dx[i]] = 1;
                    num_b++;
                }
            }
        }
        //cout<<p.e1<<sspace<<p.e2<<sspace<<visited[p.e1][p.e2]<<endl;
    }

    //cout<<num_b<<sspace<<num_w<<endl;
    return (ll)num_b * num_w;
}

int main()
{
    cin>>H>>W;
    REP(i,H) s.push_back(input<string>());

    REP(i,H) {
        REP(j,W) {
            if (s[i][j] == '#' && visited[i][j] == 0) {
                ans += bfs(i, j);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
