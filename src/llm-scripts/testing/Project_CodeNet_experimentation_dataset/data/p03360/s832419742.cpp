#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, sum=0;
	vector<int> v1(3);
	for(int i=0;i<3;i++)
	{
	    cin>>v1[i];
	}
		cin>>k;
	sort(v1.begin(),v1.end());
	for(int i=1;i<=k;i++){
	v1[2]=v1[2]*2;}
	for(int i=0;i<3;i++)
	{
	    sum+=v1[i];
	}
    cout<<sum<<"\n";
	return 0;
}
