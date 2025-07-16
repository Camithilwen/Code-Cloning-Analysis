#include<bits/stdc++.h>
using namespace std;
int main(void){
	int a[4];
	for(int i=0;i<4;i++)	cin>>a[i];
	int e,f;
	cin>>e>>f;
	sort(a,a+4,greater<int>());
	if(e<f){
		cout<<a[0]+a[1]+a[2]+f<<endl;
	}
	else{
		cout<<a[0]+a[1]+a[2]+e<<endl;
	}
	return 0;
}
