#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int val=1;
	int cnt=0;
	int ans[n+1]={0};
	for(int i=n-1;i>=0;i--){
		if(a[i]==val){
			cnt++;
			ans[val]=1;
			while(ans[val]==1){
				val++;
			}
		}
		ans[a[i]]=1;
	}
	cout << cnt << endl;
}
