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
    int d; cin >> d;
    ll g; cin >> g;
    vector<ll> p(d);
    vector<ll> c(d);
    rep(i, d) cin >> p[d - 1 - i] >> c[d - 1 - i];

    int min_count = 100000000;
    int count, sum;
    bool flag;
    for(int bit = 0; bit < (1 << d); bit++){
        flag = false;
        count = 0; 
        sum = 0;
        for(int i = 0; i < d; i++){
            if(bit & (1 << i)){
                int num;
                if((g - sum) > (d - i) * 100 * p[i] + c[i]){
                    sum += (d - i) * 100 * p[i] + c[i];
                    count += p[i];
                }else{
                    num = min(((g - sum) + ((d - i) * 100) - 1) / ((d - i) * 100), p[i]);
                    count += num;
                    flag = true;
                }
            }
            if(flag) break;
        }
        //cout << count << endl;
        if(flag) min_count = min(count, min_count);
    }
    cout << min_count << endl;
}