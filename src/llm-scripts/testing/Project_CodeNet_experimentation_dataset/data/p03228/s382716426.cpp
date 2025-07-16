#include<iostream>
using namespace std;
int main(){
	int a,b,k,i;
	cin>>a>>b>>k;
	for(i=0;i<k;i++){
		if(i&1){
			a+=(b>>=1);
		}else{
			b+=(a>>=1);
		}
	}
	cout<<a<<" "<<b;
	return 0;
}