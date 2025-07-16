#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll Power[20];
ll dfs(ll l , ll r , ll d) {
    if(l >= r) {
        if(d == 0) return l == r ? 10 : 1;
        return 0;
    }
    if(d % 10 == 0) {
        if(l != 1) return 10 * dfs(l + 1 , r - 1 , d / 10);
        return 9 * dfs(l + 1 , r - 1 , d / 10);
    }
    ll differ = d % 10 - 10;//选取的数一定要使l位进1否则取反之后的必定小与改数，那么显然不可能。所以differ是d % 10 - 10
    ll next = d - differ + differ * Power[r - l];//这里先让d进一位，然后由于对称性，r位+differ=l位+differ所以选择+ differ * Power[r - l]，这样才能满足对称条件
    if(l == 1) return (9 + differ) * dfs(l + 1 , r - 1 , abs(next) / 10);
    return (10 + differ) * dfs(l + 1 , r - 1 , abs(next) / 10);
}
int main() {
    ll d;
    cin >> d;
    Power[0] = 1;
    for(int i = 1 ; i <= 18 ; i++) {
        Power[i] = Power[i - 1] * 10;
    }
    ll ans = 0;
    for(int i = 2 ; i <= 18 ; i++) {
        ans += dfs(1 , i , d);
    }//这里选择18位由于原来的数也就最多9位，如果取得数位数是两倍的话显然是不可能的。
    cout << ans << endl;
    return 0;
}