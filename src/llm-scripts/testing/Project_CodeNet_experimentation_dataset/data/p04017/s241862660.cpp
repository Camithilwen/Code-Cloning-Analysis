#include<bits/stdc++.h>
#define maxn 100005
#define endl '\n'
using namespace std;
int arr[maxn],brr[maxn],pre[maxn];
struct sqrtd {
	int next,cnt;
}table[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	for(int i=1;i<n;i++)
		brr[i] = arr[i+1] - arr[i] , pre[i] = brr[i] + pre[i-1];
	n--;
	
	int L;
	cin >> L;
	
	int box = sqrt(n);
	for(int i=1;i<=n;i++) {
		int tem_cnt = 0 , bound = min((i/box+1)*box,n);
		int j , sum = 0;
		for(j=i;j<=bound;) {
			sum = 0;
			do {
				sum += brr[j++];
			} while(j <= bound && sum + brr[j] <= L);
			tem_cnt++;
		}
		if(j > bound && j <= n && sum + brr[j] <= L) {
			int l = j , r = n , m;
			while(true) {
				if(r-l<3) {
					for(m=l;m<=r && pre[m]-pre[j-1]+sum <= L;m++);
					break;
				}
				m = (l+r)>>1;
				if(pre[m]-pre[j-1]+sum <= L)
					l = m;
				else
					r = m-1;
			}
			j = m;
		}
		table[i] = {j,tem_cnt};
	}
	
	int q;
	cin >> q;
	while(q--) {
		int l,r;
		cin >> l >> r;
		if(l > r)	swap(l,r);
		r--;
		int ans = 0;
		while(l <= r && l/box != r/box) {
			ans += table[l].cnt;
			l = table[l].next;
		}
		if(l <= r && l/box == r/box) {
			while(l <= r) {
				int sum = 0;
				do {
					sum += brr[l++];
				} while(l <= r && sum + brr[l] <= L);
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
