#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int a[n+2];
	a[0]=0;
	a[n+1]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	int b[n+1]; //b[i]=cost of i->i+1
	int sum=0;
	for(int i=0;i<=n;i++){
		b[i]=abs(a[i+1]-a[i]);
		sum+=b[i];
	}
	
	for(int i=1;i<=n;i++)
		cout<<sum-b[i-1]-b[i]+abs(a[i+1]-a[i-1])<<endl;
}
