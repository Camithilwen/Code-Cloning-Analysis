#include <bits/stdc++.h>
#include <math.h>

using namespace std;

template<typename T>
long long modpow(const T n,const T p,const T mod);
template<typename T>
long long modinv(const T n,const T mod);
template<typename T>
bool chmax(T &a,const T &b);
template<typename T>
bool chmin(T &a,const T &b);

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<long long> zero(62,0),one=zero;

	for(long long i=0;i<n;i++){
		long long hoge;
		cin>>hoge;
		bitset<62> bit=hoge;

		for(long long i=0;i<62;i++){
			if(bit.test(i)) one.at(i)++;
			else zero.at(i)++;
		}
	}

	long long ans=0;
	long long two=1;

	for(long long i=0;i<62;i++){
		ans+=(two*zero.at(i))%inf*one.at(i);
		ans%=inf;
		two*=2;
		two%=inf;
	}

	cout<<ans<<endl;

	return 0;
}

template<typename T>
long long modpow(const T n,const T p,const T mod){
	if(p==0) return 1;
	if(p%2==0){
		long long a=modpow(n,p/2,mod);
		return a*a%mod;
	}
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}

template<typename T>
long long modinv(const T n,const T mod){
	return modpow(n,mod-2,mod);
}

template<typename T>
bool chmax(T &a,const T &b){
	if(a<b){
		a=b;
		return 1;
	}
	return 0;
}

template<typename T>
bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return 1;
	}
	return 0;
}
