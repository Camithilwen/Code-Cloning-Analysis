#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[4],b,c;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>b>>c;
	sort(a,a+4);
	if(b>c)swap(b,c);
	cout<<a[1]+a[2]+a[3]+c<<endl;
	return 0;
	}

