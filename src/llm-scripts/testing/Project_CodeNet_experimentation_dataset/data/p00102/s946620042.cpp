#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

	int N;
	while(cin>>N,N){
		vector<int> vi(N*N,0),vi2(N*2+1,0);
		for(int i=0;i<N;i++){
			int sum=0;
			for(int j=0;j<N;j++){
				int num;
				cin>>num;
				vi[i*N+j]=num;
				sum+=num;
			}
			vi2[i]=sum;
		}
		for(int i=0;i<N;i++){
			int sum=0;
			for(int j=0;j<N;j++){
				sum+=vi[i+j*N];
				printf("%5d",vi[i*N+j]);
			}
			printf("%5d\n",vi2[i]);
			vi2[N*2]+=vi2[i];
			vi2[N+i]=sum;
		}
		for(int i=0;i<=N;i++){
			printf("%5d",vi2[N+i]);
		}
		cout<<endl;
	}

	return 0;
}