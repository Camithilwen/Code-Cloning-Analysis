#include<iostream>
int main(){
	int N;
	std::cin>>N;
	long int* A=new long int[N];
	long sum=0;
	for(int i=0;i<N;i++){
		std::cin>>A[i];
		sum+=A[i];
		sum%=1000000007;
	}
	long ans=0;
	for(int i=0;i<N;i++){
		sum-=A[i];
		if(sum<0){
			sum+=1000000007;
		}
		ans+=sum*A[i];
		ans%=1000000007;
	}
	std::cout<<ans;
	return 0;
}
