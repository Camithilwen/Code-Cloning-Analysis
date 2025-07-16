#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,q[40003];
long long ans,c[50];
int main(){
	cin>>n;
	char _a;
	for(int i=1,_n=n+1;i<_n;i++){
		cin>>_a;
		switch(_a){
			case 'R':
				q[i]=1;
				break;
			case 'G':
				q[i]=2;
				break;
			case 'B':
				q[i]=4;
				break;
		}
		c[q[i]]++;
	}
	ans=1ll*c[1]*c[2]*c[4];
	for(int i=1,_m=n-1;i<_m;i++){
		for(int j=i+1,_n=n+1;j<_n;j++){
			ans-=((q[i]|q[j]|q[j+j-i])==7);
		}
	}
	cout<<ans;
	return 0;
}

