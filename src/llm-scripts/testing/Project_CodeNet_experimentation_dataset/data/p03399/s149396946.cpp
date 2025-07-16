#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define xx first
#define yy second
 
#define pii pair <int, int >
#define pll pair < ll, ll >
#define xx first
#define yy second
#define vi vector < int >
#define vl vector < ll >
#define vp vector < pii >
 
#define inf  100000000
 
#define f(i, c, n) for(int i = c; i < n; i++)
#define fe(i, c, n) for(int i = c; i <= n; i++)
#define fr(i, n, c) for(int i = n - 1; i >= c; i--)
 
#define be(a) a.begin(), a.end()
#define vsort(a) sort(a.begin(), a.end())
#define mem(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define srti(a, n) sort(a, a + n)
#define srtd(a, n) sort(a, a + n, greater<int>())
#define LB(a, x) (lower_bound(vbe(a), x) - a.begin())
#define UB(a, x) (upper_bound(vbe(a), x) - a.begin())
#define S " "
#define N "\n"

//cout << "Case " << ++cs << ": " <<
#define fast ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int mn = min(a, b);
	mn += min(c, d);
	cout << mn << N;
}

int main() {
    // FILE;
    fast;
    // int t; cin >> t; while(t--)
    solve();
}