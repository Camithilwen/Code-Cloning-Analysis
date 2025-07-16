#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int mod=1e9+7;

int modpow(long a,int p){
	long res=1;
	while(p){
		if(p&1) (res*=a)%=mod;
		(a*=a)%=mod;
		p>>=1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int x[n];
	x[0]=a[0];
	for(int i=1;i<n;i++) x[i]=a[i]^x[i-1];
	map<int,vector<int>> m;
	for(int i=0;i<n;i++) if(x[i]) m[x[i]].push_back(i);

	long ans=0;
	if(x[n-1]==0){
		int znum[n];
		znum[0]=(x[0]==0);
		for(int i=1;i<n;i++) znum[i]=znum[i-1]+(x[i]==0);
		long res=0;
		for(auto p:m){
			vector<int> v=p.second;
			long z=1,o=0;
			int cur=0;
			for(int i:v){
				long zero=znum[i]-znum[cur];
				long zn=(o*zero+z)%mod;
				long on=(zn+o)%mod;
				z=zn;
				o=on;
				cur=i;
			}
			(res+=o)%=mod;
		}
		(res+=modpow(2,znum[n-1]-1))%=mod;
		ans=res;
	}else{
		int y=x[n-1];
		long z=1,o=0;
		for(int i=0;i<n;i++){
			if(x[i]==0) (z+=o)%=mod;
			else if(x[i]==y) (o+=z)%=mod;
		}
		ans=z;
	}
	cout << ans << endl;
	return 0;
}
