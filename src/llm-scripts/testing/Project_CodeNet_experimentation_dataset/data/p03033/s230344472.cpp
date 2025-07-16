#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N,Q;
cin >> N >> Q;

map<int,vi> add;
map<int,vi> era;
map<int,int> mp;

rep(i,N) {
    int s,t,x;
    cin >> s >> t >> x;
    add[max(0,s-x)].push_back(x);
    era[max(1,t-x)].push_back(x);
    mp[max(0,s-x)] = 0;
    mp[max(1,t-x)] = 0;
}
rep(i,Q) {
    int d;
    cin >> d;
    mp[d] = 1;
}

set<int> st;

for(auto x : mp) {

    for(auto erx : era[x.first]) {
        st.erase(erx);
    }
    for(auto adx : add[x.first]) {
        st.insert(adx);
    }
    if(x.second == 1) {
        if(!st.empty()) {
            cout << *st.begin() << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}

return 0;
}