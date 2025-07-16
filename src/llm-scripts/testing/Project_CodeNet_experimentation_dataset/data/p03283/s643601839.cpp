#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

int main(){
    int n, m, q; cin >> n >> m >> q;

    int a, b;
    vector<vector<int>> count(501, vector<int>(501, 0));
    rep(i, m){
        cin >> a >> b;
        count[a][b]++;
    }
    vector<vector<int>> sum(501, vector<int>(501, 0));
    _rep(i, 1, n + 1)_rep(j, 1, n + 1){
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + count[i][j]; 
    }
    rep(i, q){
        cin >> a >> b;
        cout << sum[b][b] - sum[b][a - 1]- sum[a - 1][b] + sum[a - 1][a - 1] << endl;
    }
}