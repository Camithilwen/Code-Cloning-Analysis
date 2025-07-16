#include<iostream>
using namespace std;
int a[1000005];
int main(){
	int k,i;
	cin>>a[0]>>a[1]>>k;
	for(i=0;i<k;i++){
		a[!(i&1)]+=(a[i&1]>>=1);
	}
	cout<<a[0]<<" "<<a[1];
	return 0;
}