#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;


#define MAX_N 10000
int prime[MAX_N];
bool is_prime[MAX_N+1];
int sieve(int n){
	int p=0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
		}
	}
	return p;
}

int main(){
	sieve(MAX_N);
	vector<int> p;
	for(int i=2;i<=MAX_N-2;i++)
		if(is_prime[i]&&is_prime[i+2])p.push_back(i+2);
	int n;
	while(cin>>n&&n){
		int a=upper_bound(p.begin(),p.end(),n)-p.begin();
		cout<<p[a-1]-2<<' '<<p[a-1]<<endl;
	}
	return 0;
}