#include<iostream>
using namespace std;
int main(){
	int n;
	string A,B,C;
	cin>>n;
	int count=0;
	cin>>A>>B>>C;
	for(int i=0;i<n;i++){
		if(A[i]==B[i]){
			if(B[i]!=C[i])
			count++;
		}
		else if(B[i]==C[i]){
			count++;
		}
		else if(A[i]==C[i]){
			count++;
		}
		else{
			count+=2;
		}
	}
	cout<<count;
}