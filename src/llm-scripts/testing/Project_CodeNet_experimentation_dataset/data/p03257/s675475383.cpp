#include <bits/stdc++.h>
using namespace std; 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

const int maxn = 505;
ll a[maxn][maxn];
int n;

const int maxm = 1e4 + 5;
bool vis[maxm];

map<int, int> zhu, fu;

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

ll lcm(ll x, ll y){
    return x / gcd(x, y) * y;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    vector<int> prime;
    vis[1] = 1;
    for(int i = 2;i < maxm;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(int j = 2 * i;j < maxm;j += i){
                vis[j] = 1;
            }
        }
    }
    int front = 0, rear = n - 1;
    for(int i = 2;i <= 2 * n;i += 2){
        int k = i / 2;
        if(k & 1){
            zhu[i] = prime[front++];
        }else{
            zhu[i] = prime[rear--];
        }
    }
    int k;
    if(n & 1)
        k = n;
    else
        k = n - 1;
    front = n, rear = n + k - 1;
    for(int i = 1 - k, odd = 1;i <= k - 1;i += 2, odd++){
        if(odd & 1){
            fu[i] = prime[front++];
        }else{
            fu[i] = prime[rear--];
        }
    }
    for(int i = 1;i <= n;i++){
        int st;
        if(i & 1){
            st = 1;
        }else{
            st = 2;
        }
        for(int j = st;j <= n;j += 2){
            int id1 = zhu[i + j];
            int id2 = fu[i - j]; 
            a[i][j] = 1LL * id1 * id2;
        }
    }
    for(int i = 1;i <= n;i++){
        int st;
        if(i & 1){
            st = 2;
        }else{
            st = 1;
        }
        for(int j = st;j <= n;j += 2){
            a[i][j] = 1;
            if(j > 1){
                a[i][j] = lcm(a[i][j], a[i][j - 1]);
            }
            if(j < n){
                a[i][j] = lcm(a[i][j], a[i][j + 1]);
            }
            if(i > 1){
                a[i][j] = lcm(a[i][j], a[i - 1][j]);
            }
            if(i < n){
                a[i][j] = lcm(a[i][j], a[i + 1][j]);
            }
            a[i][j]++;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << a[i][j] << ((j == n) ? '\n' : ' ');
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if(n == 2){
        cout << 4 << " " << 7 << endl;
        cout << 23 << " " << 10 << endl;
        return 0;
    }
    solve();
    return 0;
}
