#include<iostream>
#include<cmath>
using namespace std;
typedef long long int LL;
LL base[25];

LL check(LL a,int n,int k){
	if(n==0){
		if(a==0)return 10;
		else return 0;
	}
	if(n<0){
		if(a==0)return 1;
		else return 0;
	}
	LL b,c,d;
	LL t;
	t=base[n];
	for(int i=0;i<k;i++)t*=10;
	b=(a+t*15)/t-15;
	c=0;
	if(-9<=b && b<=9){
		d=10-abs(b);
		if(k==0 && b>=0)d--;
		c=check(a-b*t,n-2,k+1)*d;
	}
	if(-9<=b+1 && b+1<=9){
		d=10-abs(b+1);
		if(k==0 && b+1>=0)d--;
		c+=check(a-(b+1)*t,n-2,k+1)*d;
	}
	return c;
}

int main(){
	LL a,b,c;
	LL s=0;
	int i,j,k;
	for(i=1,a=1;i<=20;i++){
		a*=10;
		base[i]=a-1;
	}
	cin>>a;
	for(i=20;i>0;i--){
		s+=check(a,i,0);
	}
	cout<<s<<endl;
}
