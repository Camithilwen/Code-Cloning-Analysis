// 2014/11/05 Tazoe

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int A[1000];
	for(int i=0; i<N; i++){
		cin >> A[i];
	}

	int B[1000];
	for(int i=0; i<M; i++){
		cin >> B[i];
	}

	int cnt[1000] = {0};
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(B[i]>=A[j]){
				cnt[j]++;
				break;
			}
		}
	}

	int i_max = 0;
	for(int i=1; i<N; i++){
		if(cnt[i]>cnt[i_max]){
			i_max = i;
		}
	}

	cout << i_max+1 << endl;

	return 0;
}