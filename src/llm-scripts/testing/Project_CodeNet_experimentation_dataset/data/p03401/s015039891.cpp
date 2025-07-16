#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long

int n,a[111111]={},sum=0;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=abs(a[i]-a[i-1]);
	}
	sum+=abs(a[n]);
	for(int i=1;i<=n;i++){
		int tmp=abs(a[i-1]-a[i+1])-abs(a[i]-a[i-1])-abs(a[i+1]-a[i]);
		cout<<sum+tmp<<endl;
	}
	return 0;
}

