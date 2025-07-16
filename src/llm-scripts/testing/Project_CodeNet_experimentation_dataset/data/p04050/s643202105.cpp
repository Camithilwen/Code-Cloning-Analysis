#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
int n, m, a[105], b[105], cnt;

int main() {
	cin>>n>>m;
	rep(i, 1, m) {
		cin>>a[i];
		if(a[i]&1) cnt++;
	}
	if(cnt > 2) {
		cout<<"Impossible"<<endl;
		return 0;
	} 
	if(m == 1) {
		cout<<n<<endl;
		if(n == 1) cout<<1<<endl<<1<<endl;
		else cout<<2<<endl<<a[1] - 1<<" "<<1<<endl;
		return 0;
	}
	rep(i, 1, m)
		if(a[i]&1) {
			swap(a[i], a[1]);
			break;
		}
	rep(i, 2, m - 1) 
	    if(a[i]&1)
		   	swap(a[i], a[m]);
	rep(i, 1, m) cout<<a[i]<<" ";
	cout<<endl<<((a[m] == 1) ? m - 1: m)<<endl<<a[1] + 1<<" ";
	rep(i, 2, m - 1)
	    cout<<a[i]<<" "; 
	if(a[m] != 1) cout<<a[m] - 1<<endl;
}