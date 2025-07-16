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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    vector<int> b;
    rep(i, n){
        int a; cin >> a;
        if(b.empty()){
            b.push_back(a);
            continue;
        }else{
            auto itr = lower_bound(b.begin(), b.end(), a);
            int idx = distance(b.begin(), itr);
            if(idx == 0) b.insert(b.begin(), a);
            else b[idx - 1] = a;
        }
    }
    //for(auto it : b) cout << it << endl;
    cout << b.size() << endl;
}