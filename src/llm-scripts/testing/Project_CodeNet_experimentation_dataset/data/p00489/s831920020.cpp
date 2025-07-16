#include<iostream>
using namespace std;
int main(){
	int N,a,b,c,d;
	int i,j;
	int t[101]={0};
	int r[101];
	for(i=0;i<101;i++){
		r[i]=1;
	}
	cin>>N;
	for(i=0;i<N*(N-1)/2;i++){
		cin>>a>>b>>c>>d;
		if(c>d){
			t[a]=t[a]+3;
		}
		else if(c<d){
			t[b]=t[b]+3;
		}
		else{
			t[a]=t[a]+1;
			t[b]=t[b]+1;
		}
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(t[i]<t[j]){
				r[i]++;
			}
		}
	}
	for(i=1;i<=N;i++){
		cout<<r[i]<<endl;
	}
	return 0;
}