#include<bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long p){
	long long res = 1;
	while(n > 0){
		if(n & 1){
			res = res*a%p;
		}
		a = a*a%p;
		n >>=1;
	}
	return res;
}


int main()
{
	int n;
	long long ans = 0;
	cin>> n;
	vector<int> a(n);
	vector<int> cnt(n);
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
	
	int cnt0 = 3;
	if(a[0] == 0){
		ans = 3;
		cnt[0]++;
		cnt0--;
	}
	for(int i=1;i<n;i++){
		if(a[i] == 0){
			ans *= cnt0;
			cnt0--;
			cnt[0]++;
			if(cnt0<0) ans = 0;
		}else{
			ans *= (cnt[a[i]-1] - cnt[a[i]]);
			cnt[a[i]]++;
			if(3<cnt[a[i]]) ans = 0;
		}
		if(1E9+7<=ans) ans %= (long long)(1E9+7);
	}
	
	
	
	
	
	cout<<ans<<endl;
}
