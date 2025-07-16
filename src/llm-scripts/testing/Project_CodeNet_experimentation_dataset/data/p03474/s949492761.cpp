#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i] << " "
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
bool isPerfectSquare(long double x) {   
    long double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
} 
bool isPrime(int x){
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return 0;
    }
    return 1;
}
int fun(int n){
    if(n & 1) return 3 * n + 1;
    else return n/2;
}
int32_t main(){
    SPEED;
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int cnt = 0;
    for(char c: s) if(c == '-') cnt++;
    a--;
    if(s[a + 1] == '-' && cnt == 1) cout << "Yes";
    else cout << "No" ;
}