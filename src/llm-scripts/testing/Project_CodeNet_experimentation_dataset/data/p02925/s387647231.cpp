#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> chidx;
int n;

int check(){
    REP(i, 0, n){
        if(chidx[i] != n-1){
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n;
    chidx = vector<int>(n, 0);
    vector<vector<int> > lis(n, vector<int>(n-1));
    REP(i, 0, n){
        REP(l, 0, n-1){
            cin >> lis[i][l];
            lis[i][l]--;
        }
    }
    int ans = 0;
    while(check() == 1){
        ans++;
        vector<int> used(n, 0);
        int f = 0;
        REP(i, 0, n){
            if(chidx[i] == n-1){
                continue;
            }
            int to = lis[i][chidx[i]];
            if(used[i] == 1 || used[to] == 1){
                continue;
            }
            if(chidx[to] == n-1){
                cout << -1 << endl;
                return 0;
            }
            if(lis[to][chidx[to]] == i){
                chidx[i]++;
                chidx[to]++;
                used[i] = 1;
                used[to] = 1;
                f = 1;
            }
        }
        if(f == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}