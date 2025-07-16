#include<iostream>

using namespace std;

int main(void)
{
	int D,S,T;
	cin>>D>>T>>S;
	
	int s=T*S;
	if(s>=D){
		cout<<"Yes";
	} else{
		cout<<"No";
	}
	
	return 0;
}