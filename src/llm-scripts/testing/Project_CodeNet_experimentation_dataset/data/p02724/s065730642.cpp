#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int,int>;
int main(){
    int64_t x,ans;
    cin >> x;
    int a,b,c;
    a = x/500;
    b = x - 500*a;
    c = b/5;
    ans = 1000*a + c*5;
    cout << ans << endl;
    
}