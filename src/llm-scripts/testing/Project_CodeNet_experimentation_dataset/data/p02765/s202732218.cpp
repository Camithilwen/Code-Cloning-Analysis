#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, R;
    cin >> N >> R;
    int ans;
    if(N >= 10){ans = R;}
    else{ans = R + (100 * (10 - N));}
    cout << ans << endl;
    return 0;
}
