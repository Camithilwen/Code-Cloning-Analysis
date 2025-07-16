#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7, mul = (1 << 30);

int n, pw[200005], a[200005], b[200005], hash1[200005], hash2[200005], c[200005], d[200005];
vector<ii> answers;

int hash11(int l, int r){
    return (hash1[r] - (hash1[l - 1] * pw[r - l + 1]) + mod * mod) % mod;
}

int hash22(int l, int r){
    return (hash2[r] - (hash2[l - 1] * pw[r - l + 1]) + mod * mod) % mod;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i < n; i++) c[i] = (a[i] ^ a[i + 1]);
	c[n] = (a[n] ^ a[1]);
	for(int i = 1; i < n; i++) d[i] = (b[i] ^ b[i + 1]);
	d[n] = (b[n] ^ b[1]);
	//for(int i = 1; i <= n; i++) cout << c[i] << " ";
	//cout << "\n";
	//for(int i = 1; i <= n; i++) cout << d[i] << " ";
	//cout << "\n";
	for(int i = 1; i <= n; i++) hash1[i] = (hash1[i - 1] * mul + c[i]) % mod;
	for(int i = 1; i <= n; i++) hash2[i] = (hash2[i - 1] * mul + d[i]) % mod;
	pw[0] = 1;
	for(int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * mul) % mod; 
	for(int i = 1; i <= n; i++){
	    //cout << hash11(1, n - i + 1) << " " << hash22(i, n) << "\n";
	    if(hash11(1, (n - i + 1)) != hash22(i, n) || ((i != 1) && (hash11(n - i + 2, n) != hash22(1, i - 1)))) continue;
	    answers.pb({(n - i + 1) % n, b[i] ^ a[1]});
	}
	sort(answers.begin(), answers.end());
	for(int i = 0; i < answers.size(); i++) cout << answers[i].fi << " " << answers[i].se << "\n";
}

/*
TEST HERE
INPUT #1

OUTPUT #1


INPUT #2

OUTPUT #2


INPUT #3

OUTPUT #3

*/
