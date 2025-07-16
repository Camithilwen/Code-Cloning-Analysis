#include<bits/stdc++.h>
using namespace std;

int N,arr[200200],mod = 1e9 + 7;
long long prefix[200200],sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i = 1;i <= N;i++){
		cin>>arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for(int i = 2;i <= N;i++){
		sum += (prefix[i - 1] % mod) * (arr[i] % mod);
		sum %= mod;
	}
	cout<<sum<<endl;
}
