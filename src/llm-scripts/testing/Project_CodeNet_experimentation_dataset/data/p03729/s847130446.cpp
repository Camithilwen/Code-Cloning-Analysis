#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    string a, b, c;
    cin >> a >> b >> c;
    if(a.back() == b.front()){
        if(b.back() == c.front()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}