#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;


const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}


int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];;
    }
    REP(i,k){
        vector<int> b(n, 0);
        REP(i, n)
        {
            int l = max(0LL, i - a[i]);
            int r = min(n - 1, int(i + a[i]));
            b[l]++;
            if (r + 1 < n)
            {
                b[r + 1]--;
            }
        }
        a[0]=b[0];
        int ndesu=0;
        if(a[0]==n){
            ndesu++;
        }
        REP(j, n)
        {
            if (j == 0)
                continue;
            b[j] += b[j - 1];
            a[j]=b[j];
            if(a[j]==n){
                ndesu++;
            }
        }
        if(ndesu==n){
            REP(j,n){
                cout << n << " ";
            }
            cout << endl;
            return 0;
        }
    }
    REP(i,n){
        cout << a[i] << " ";
    }
    cout << endl;
}
