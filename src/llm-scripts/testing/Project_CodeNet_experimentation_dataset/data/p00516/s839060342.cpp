#include<iostream>
using namespace std;

int N,M,A[1001],B,V[1001];
int main(int i,int j){
	cin>>N>>M;
	for(;i<=N+M;i++){
		cin>>((i<=N)?A[i]:B);
		for(j=1;j<=N;j++){
			if(i>N&&B>=A[j]){
				V[j]++;break;
			}
		}
	}
	int max=0;
	for(i=1;i<=N;i++){
		if(max<V[i]){
			max=V[i];j=i;
		}
	}
	cout<<j<<endl;
	return 0;
}