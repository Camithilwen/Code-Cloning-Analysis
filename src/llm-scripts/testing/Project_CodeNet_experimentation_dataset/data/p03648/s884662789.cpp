#include <iostream>
using namespace std;
using lint = long long;

lint K;
lint N = 50;
const int MAX_N = 55;
lint a[MAX_N];

int main(){
	ios::sync_with_stdio(false);
	cin>>K;

	for(int i=0;i<N;i++){
		a[i] = (K+N-1)/N+(N-1);
	}

	int t = N-K%N;
	if(t==N)t=0;
	for(int i=0;i<t;i++){
		a[i]-=K%N+1;
	}

	cout << N << endl;
	for(int i=0;i<N;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}