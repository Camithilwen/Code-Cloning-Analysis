#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int cnt[10800];
int main(){  
	int n, q, m, d;
	while(cin >> n >> q, n | q){
		fill(cnt, cnt + 10800, 0);
		int res = 0;
		int mx = 0;
		for(int i = 0;i < n;i++){
			cin >> m;
			for(int j = 0;j < m;j++){
				cin >> d;
				cnt[d]++;
				mx = max(mx, cnt[d]);
			}
		}
		for(int i = 10799;i >= 0;i--){
			if(mx >= q && cnt[i] == mx)res = i;
		}
		cout << res << endl;
	}
	return 0;
}