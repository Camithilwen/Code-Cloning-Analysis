#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    for(int i = 0; i < k; i++){
        if(a < b){
            if(b < c) c *= 2;
            else b *= 2;
        }
        else{
            if(a < c) c *= 2;
            else a *= 2;
        }
    }
    cout << a + b + c << endl;
    
    return 0;
}