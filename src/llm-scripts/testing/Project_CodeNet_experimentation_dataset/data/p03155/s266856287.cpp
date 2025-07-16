#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,h,w,res1,res2;
signed main(){
	cin>>n>>h>>w;
	res1=n-h;
	res1++;
	res2=n-w;
	res2++;
	res1=res1*res2;
	cout<<res1<<endl;
	return 0;
}