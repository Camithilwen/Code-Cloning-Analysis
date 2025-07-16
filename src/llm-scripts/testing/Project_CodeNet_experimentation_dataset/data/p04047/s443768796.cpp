#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,p;
	cin>>n;
	vector<int>v;
	for(int i=0;i<2*n;i++){
		cin>>p;
		v.push_back(p);
	}
	sort(v.begin(),v.end());
	long res=0;
	for(int i=0;i<2*n;i+=2){
		res+=min(v[i],v[i+1]);
	}
	cout<<res;
	return 0;
}