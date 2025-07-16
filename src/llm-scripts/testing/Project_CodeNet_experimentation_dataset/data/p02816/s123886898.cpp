#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 4e5 + 7;

int a[N], b[N], ok[N], okk[N], c[N], d[N], fail[N];
int n;

void goo() {
	for(int i=1,j=fail[0]=-1;i<n;i++) {
		while(j >= 0 && d[j+1] != d[i])
			j = fail[j];
		if(d[j+1] == d[i])
			j++;
		fail[i] = j;
	}
	for(int i=0,j=-1;i<2*n;i++) {
		while(j >= 0 && (j == n - 1 || d[j+1] != c[i]))
			j = fail[j];
		if(d[j+1] == c[i])
			j++;
		if(j == n - 1) okk[i-n+1] = 1;
	}
}

void go(int bit) {
	for(int i=0;i<2*n;i++)
		c[i] = a[i] >> bit & 1;
	for(int i=0;i<n;i++)
		d[i] = b[i] >> bit & 1;
	for(int i=0;i<n;i++) okk[i] = 0;
	goo();
	for(int i=0;i<n;i++)
		d[i] ^= 1;
	goo();
	for(int i=0;i<n;i++) ok[i] &= okk[i];
}

signed main()
{
	IO_OP;	

	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		a[i+n] = a[i];
		ok[i] = 1;
	}	
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<30;i++)
		go(i);
	for(int i=0;i<n;i++)
		if(ok[i]) cout << i << " " << (a[i] ^ b[0]) << endl;
}



