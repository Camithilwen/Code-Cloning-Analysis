#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int x,y;
	cin>>x>>y;

	vector<long long> score={300000,200000,100000,0};

	long long ans=0;

	ans+=score.at(min(3,x-1));
	ans+=score.at(min(3,y-1));

	if(x==1 && y==1) ans+=400000;

	cout<<ans<<endl;

	return 0;
}
