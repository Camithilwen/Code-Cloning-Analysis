#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n=2;
	vector<int> p[2];
	int ans[2];
	for(int i=0;i<n;++i){
		for(int j=0,point;j<10;++j){
			cin>>point;
			p[i].push_back(point);
		}
		sort(p[i].begin(),p[i].end(),greater<int>());
		ans[i]=p[i][0]+p[i][1]+p[i][2];
	}
	for(int i=0;i<n;++i)cout<<ans[i]<<((i==n-1)?"\n":" ");
	return 0;
}