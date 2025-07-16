#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
using namespace std;
#define maxn long long(5*1e8)

int main(){
	long long n=0;
	scanf("%d",&n);	
	map<long long,long long,greater<long long>> num;
	for(long long i=1;i<=n;++i){
		long long temp=0;
		scanf("%d",&temp);
		num[temp]++;
	}
	long long j=pow(2.0,31),ans=0;
	for(auto iter=num.begin();iter!=num.end();++iter){
		while(iter->first<j/2) j/=2;
		if(num[iter->first]>0&&num[j-iter->first]>0){
				if(j==iter->first*2){
					ans+=num[iter->first]/2;
					num[iter->first]=num[iter->first]%2;
				}
				else{
				ans+=min(num[iter->first],num[j-iter->first]);
				num[j-iter->first]-=min(num[iter->first],num[j-iter->first]);
				}
			}
	}
	cout<<ans<<endl;
}
//5 1 2 2 2 3
