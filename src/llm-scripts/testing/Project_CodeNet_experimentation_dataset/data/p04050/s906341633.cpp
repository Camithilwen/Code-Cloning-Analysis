#include <iostream>
#include <algorithm>
using namespace std;

int A[110], ans[110];

int main() {
	int N, M;
	cin >> N >> M;
	int cnt=0;
	for(int i=0; i<M; ++i){
		cin >> A[i];
		cnt += A[i]%2;
	}
	if(cnt>2){
		cout << "Impossible" << endl;
		return 0;
	}
	if(cnt>0){
		bool flag=false;
		for(int i=0; i<M; ++i){
			if(A[i]%2==1){
				if(flag){
					swap(A[i], A[M-1]);
				}else{
					swap(A[i], A[0]);
					flag=true;
				}
			}
		}
	}
	cout << A[0];
	for(int i=1; i<M; ++i) cout << ' ' << A[i];
	cout << endl;
	int bs=0;
	if(A[0]>1){
		ans[bs]=A[0]-1;
		++bs;
	}
	A[0]=2;
	for(int i=0; i<M-1; ++i){
		ans[bs]=A[i];
		++bs;
	}
	if(A[M-1]>1){
		ans[bs]=A[M-1]-1;
		++bs;
	}
	cout << bs << endl;
	cout << ans[0];
	for(int i=1; i<bs; ++i) cout << ' ' << ans[i];
	cout << endl;
	return 0;
}