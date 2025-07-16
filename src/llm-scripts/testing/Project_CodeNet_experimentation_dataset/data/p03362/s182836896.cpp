#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

vector<bool> IsPrime;

void sieve(size_t max){
    IsPrime.assign(max + 1, true);
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i = 2; i*i <= max; i++){
        if(IsPrime[i])for(int j = 2; i*j <= max; j++) IsPrime[i*j] = false;
    }
}

int main(){
    sieve(55555);
    int cnt;
    vector<int> ans;
    for(int i = 1; i<= 55555; i++){
        if(i%5 == 1 && IsPrime[i] == true)ans.push_back(i);
    }
    int N; cin >> N;
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}