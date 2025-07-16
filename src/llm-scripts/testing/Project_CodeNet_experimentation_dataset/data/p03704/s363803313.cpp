#include<iostream>
#include<algorithm>
using namespace std;

#define long long long

long sol(long);

int main(){
	long a=0;
	cin>>a;
	cout<<sol(a)<<endl;
	return 0;
}

long pow10(long a){
	if(a<0)return 0;
	long r=1,c=10;
	while(a>0){
		if(a&1)r*=c;
		c*=c;
		a>>=1;
	}
	return r;
}

long will[50];

long dfs(long d,long pos,long n,long ned){
	if(abs(d-ned)>pow10(n-pos+1)-pow10((n+1)/2)-pow10(n/2)+pow10(pos-1))return 0;
	if(pos>(n+1)/2)return ned==d;
	long ans=0;
	for(will[pos]=-9;will[pos]<=9;will[pos]++){
		if(pos==1&&will[pos]==9)continue;
		if(pos==n/2+1&&will[pos]!=0)continue;
		if(will[pos]>=0)ans+=(9-will[pos]+(pos!=1))*dfs(d+(pow10(n-pos)-pow10(pos-1))*will[pos],pos+1,n,ned);
		else ans+=(10+will[pos])*dfs(d+(pow10(n-pos)-pow10(pos-1))*will[pos],pos+1,n,ned);
	}
	will[pos]=0;
	return ans;
}

long sol(long d){
	if(d%9)return 0;
	long ans=0;
	for(long i=2;pow10((i+1)/2)-pow10((i-1)/2)<=d;i++)
		ans+=dfs(0,1,i,d);
	return ans; 
}