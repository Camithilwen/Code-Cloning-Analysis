#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,l=100,s=0;
	for(int i=0;i<4;i++){
		cin>>a;
		s+=a;
		l=min(a,l);
	}
	cin>>a>>b;
	cout<<s-l+max(a,b)<<endl;
	return 0;
}