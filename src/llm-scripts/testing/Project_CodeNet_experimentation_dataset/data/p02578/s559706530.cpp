#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long N,ans=0;
	cin>>N;
	vector<long long> A(N);
	for(int i=0;i<N;i++) cin>>A[i];

	for(int i=1;i<N;i++){
		if(A[i]<A[i-1]){
			ans+=A[i-1]-A[i];
			A[i] = A[i-1];
		}
	}
	cout<<ans<<endl;
}