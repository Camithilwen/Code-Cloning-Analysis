#include<bits/stdc++.h>
#define maxn 100005
#define endl '\n'
using namespace std;
int arr[maxn],ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;i++)
		arr[i+1] = (s[i] == 'o' ? 0 : 1);
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++) {
			ans[1] = i;
			ans[2] = j;
			for(int k=3;k<=n;k++)
				ans[k] = (arr[k-1] ^ ans[k-1] ^ ans[k-2]);
			if(arr[n] == (ans[n-1] ^ ans[1] ^ ans[n]) && arr[1] == (ans[n] ^ ans[2] ^ ans[1])) {
				for(int i=1;i<=n;i++)
					cout << (ans[i] == 0 ? 'S' : 'W');
				cout << endl;
				return 0;
			}
		}
	cout << -1 << endl;
	return 0;
}
