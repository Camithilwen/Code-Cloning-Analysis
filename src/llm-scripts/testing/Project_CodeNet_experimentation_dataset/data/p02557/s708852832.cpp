#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MOD (ull)(double)(1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
#define debug(x) cout << #x << " " << x << endl
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";cout << '\n';
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];

const long double PI = 3.141592653589793238462643383279502884197169399;

// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))

void solve(){
	int n;
	cin >> n;
	
	vi a(n);
	for(int& x : a)cin >> x;
	
	vi b(n);
	for(int& x : b)cin >> x;
	
	reverse(all(b));
	
	int l=0, r=n-1;
	for(int i=0 ; i<n ; ++i){
		if(a[i] == b[i]){
			if(a[l] != b[i] && b[l] != b[i]){
				swap(b[i], b[l]);
				++l;
			}
			else if(a[r] != b[i] && b[r] != b[i]){
				swap(b[i], b[r]);
				--r;
			}
			else{
				cout << "No\n";
				return;
			}
		}
	}
	
	for(int i=0 ; i<n ; ++i){
		if(a[i] == b[i]){
			cout << "No\n";
			return;
		}
	}
	
	cout << "Yes\n";
	for(int& x : b)cout << x << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed << setprecision(10);
	
	int tt=1;
	//cin >> tt;
	
	while(tt--){
		solve();
	}
}
