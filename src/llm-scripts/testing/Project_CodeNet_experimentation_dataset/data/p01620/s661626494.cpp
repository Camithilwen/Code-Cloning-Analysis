#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

int main(){
    cin.sync_with_stdio(false);
    int n;
    while(cin >> n, n) {
        int key[n];
        rep(i, n) cin >> key[i];
        string s;
        cin >> s;
        int i = 0;
        rep(j, s.size()) {
            if ('a' <= s[j] && s[j] <= 'z') {
                if (key[i] <= 26) {
                    if (s[j] - 'a' >= key[i]) s[j] = (char)(s[j] - key[i]);
                    else s[j] = (char)('Z' - (key[i] - (s[j] - 'a') - 1));
                } else {
                    s[j] = (char)(s[j] + ('A' - 'a'));
                    if (s[j] - 'A' >= key[i] - 26) s[j] = (char)(s[j] - key[i] + 26);
                    else s[j] = (char)('z' - (key[i] - (s[j] - 'A') - 27));
                }
                i = (i + 1) % n;
            } else {
                if (key[i] <= 26) {
                    if (s[j] - 'A' >= key[i]) s[j] = (char)(s[j] - key[i]);
                    else s[j] = (char)('z' - (key[i] - (s[j] - 'A') - 1));
                } else {
                    s[j] = (char)(s[j] - ('A' - 'a'));
                    if (s[j] - 'a' >= key[i] - 26) s[j] = (char)(s[j] - key[i] + 26);
                    else s[j] = (char)('Z' - (key[i] - (s[j] - 'a') - 27));
                }
                i = (i + 1) % n;
            }
        }
        cout << s << endl;
    }

    return 0;
}