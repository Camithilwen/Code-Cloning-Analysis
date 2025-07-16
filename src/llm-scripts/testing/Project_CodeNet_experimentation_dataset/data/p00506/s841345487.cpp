#include<iostream>
using namespace std;
int main(void)
{
	int n,i,j=1,max,a[3];
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	if(n==2){
		if(a[1]<=a[0]) max=a[0];
		else max=a[1];
		while(1){
			if(j==max) break;
			if(a[0]%j==0 && a[1]%j==0){
				cout<<j<<endl;
			}
			j+=1;
		}
	}
	if(n==3){
		if(a[0]>=a[1] && a[0]>=a[2]) max=a[0];
		else if(a[1]>=a[0] && a[1]>=a[2]) max=a[1];
		else max=a[2];
		while(1){
			if(j==max) break;
			if(a[0]%j==0 && a[1]%j==0 && a[2]%j==0){
				cout<<j<<endl;
			}
			j+=1;
		}
	}
	return 0;
}
