#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1e9+7;
// const ll INF = 1000000000000000000LL;

 //使い方
 int main() {
	 ll n;
	 cin >> n;
	 vector<int> a(n);
	 vector<int> ans(n);
	 rep(i,n) cin >> a[i];
	 for(int i=n-1;i>=0;i--){
		 int num = i+1;
		 ans[i] = a[i];
		 if(ans[i]==1){
			for(int j=1;j*j<=num;j++){
					if(num % j ==0){
						int x = j;
						int y = num / j;
						a[x-1] = 1 - a[x-1];
						if(x!=y)
							a[y-1] = 1 - a[y-1];
					}		 
				}
		 }
	 }
	 int cnt = 0;
	 vector<int> ans_vec;
	 rep(i,n){
		 if(ans[i]){
			  cnt++;
				ans_vec.push_back(i+1);
		 }
	 }
	 cout << cnt << endl;
	 if(cnt==0) return 0;
	 rep(i,ans_vec.size()){
		 cout << ans_vec[i] << ' ';
	 }
	 cout << endl;
 }