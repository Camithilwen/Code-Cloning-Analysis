#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int N,Q;
	while(1){
	cin>>N>>Q;if(N==0&&Q==0)break;
	int n;
	int d[10002]={};
	for(int i=0;i<N;i++)
	{cin>>n;
	for(int j=0;j<n;j++)
	{int x;	cin>>x;d[x]++;}
	}
	int c=0;int p=0;
	for(int i=0;i<10001;i++)
		if(d[i]>=Q&&d[i]>c){c=d[i];p=i;}

	cout<<p<<endl;
	}
	return 0;
}


	