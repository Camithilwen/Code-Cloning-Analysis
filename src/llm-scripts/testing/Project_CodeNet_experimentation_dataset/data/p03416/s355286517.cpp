// VU TRUONG AN
#include <bits/stdc++.h>
#define F first
#define S second
#define maxn 200005
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define pi acos(-1)
#define bit(p,x) ((x>>p) & 1)
#define Task "CF"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int > piii;

const int base = 200003;
const long long MM = 1ll * MOD * MOD;

int n;

bool Count(int x){
    string s;
    while(x > 0){
        int pos = x % 10;
        s += pos + '0';
        x /= 10;
    }
    n = s.length();
    s = " " + s;
    for(int i = 1;i <= n / 2;++i){
        if(s[i] != s[n - i + 1]) return 0;
    }
    return 1;
}

void Solve(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a;i <= b;++i){
        ans += Count(i);
    }
    cout << ans;
}

void NumTime(){cerr << "Toi" << "\n";cerr << "Di" << "\n";cerr << "Chep" << "\n";cerr << "Code" << "\n";}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
#endif
    int test = 1;
//    cin >> test;
    while(test--){
        NumTime();
        Solve();
    }
}
