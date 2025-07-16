/*program by mangoyang*/
#pragma GCC optimize("Ofast", "inline")
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int ch = 0, f = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
const int N = 1000005;
int a[N], n, m, p, v;
inline int check(int mid){
    int num = 0; ll tot = 0;
    vector<int> vec;
    for(int i = 1; i <= n; i++)
        if(a[i] <= mid){
            tot += min(mid - a[i], m);
            if(m > mid - a[i])
                vec.push_back(m - mid + a[i]);
        } 
        else num++, tot += m;
    if(num >= p) return 0;
    ll now = 1ll * v * m - tot;
    if(now <= 0) return 1;
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i = 0; i < (int) vec.size(); i++){
        now -= vec[i], num++;
        if(now <= 0) break;
    }
    if(num >= p) return 0;
    return 1;
}
int main(){
    read(n), read(m), read(v), read(p);
    for(int i = 1; i <= n; i++) read(a[i]);
    int l = 0, r = 2e9, res = 2e9;
    while(l <= r){
        int mid = (1ll * l + r) >> 1ll;
        if(check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] + m >= res) ans++;
    cout << ans << endl;
    return 0;
}