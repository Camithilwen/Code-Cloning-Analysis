#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;

using namespace std;

ll n, m, k;
ll h, w;

int main(){
    cin >> n;
    vector<ull> a(n);
    for (ll i=0; i<n; ++i){
        cin >> a[i];
    }
    ull asu=0, asq=0;
    for (ll i=0; i<n; ++i){
        asu += a[i];
        asu %= DENOM;
        asq += a[i] *a[i];
        asq %= DENOM;
    }
    ll ret = ((asu * asu) - asq) % DENOM;
    if (ret %2 ==0){
        ret /= 2;
    }else{
        ret = (ret + DENOM) / 2;
    }
    cout << ret << endl;
    return 0;
}