#include<algorithm>
#include<functional>
#include<cstdio>
#include<iostream>
using namespace std;
int flg[1000000];
int main(void)
{
	int i,j,k,n,f;
	for(i=2;i<=1000000;i++) flg[i]=1;
	for(i=2;i*i<=1000000;i++){
		if(flg[i]==1){
			for(j=2;j*i<1000000;j++) flg[i*j]=0;
		}
	}
	cin>>n;
	while(n) {
		for(i=n;i>=4;i--) {
			if(flg[i]==1&&flg[i-2]==1) {
				cout<<i-2<<" "<<i<<endl;
				break;
			}
		}
		cin>>n;
	}
}
	