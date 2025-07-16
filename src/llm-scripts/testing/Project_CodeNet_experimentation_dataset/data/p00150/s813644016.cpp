#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> P;
#define MAX 10000
 
int is_prime[MAX+5];// 1:prime 0:not prime
int ans[MAX+5];
void eratos()
{
	int i,j;
	for(i=2;i<=MAX;i++)is_prime[i]=1;
	for(i=2;i*i<=MAX;i++)if(is_prime[i]==1)
	{
		for(j=i*2;j<=MAX;j+=i)is_prime[j]=0;
	}
	return;
}
 
int main(void)
{
	eratos();
	for(int i=0;i<=MAX;i++)if(is_prime[i]&&is_prime[i+2])ans[i+2]=i+2;
	for(int i=5;i<=MAX;i++)if(ans[i]==0)ans[i]=ans[i-1];
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)break;
		cout << ans[n]-2 << ' ' << ans[n] << endl;
	}
	return 0;
}