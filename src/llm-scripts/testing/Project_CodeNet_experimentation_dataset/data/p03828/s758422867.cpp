#include <iostream>
#include <math.h>
using namespace std;

void factor(int n,int arr[]){
	for(int i=2;i<=n;i++){
		if(n%i==0){
			arr[i]+=1;
			factor(n/i,arr);
			break;
		}
		
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n+1]={0};
	for(int i=1;i<=n;i++){
		factor(i,arr);
	}
	long int result=1;
	for(int i=0;i<=n;i++){
		if(arr[i]>0){
			result*=arr[i]+1;
			result=result%(1000000000+7);
		}
   }
   cout<<result;
	
}