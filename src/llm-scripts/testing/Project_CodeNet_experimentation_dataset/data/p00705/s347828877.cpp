#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, Q;
	while(cin >> N >> Q, N){
		vector<int> cnt(101, 0);
		for(int i=0;i<N;i++){
			int M; cin >> M;
			for(int j=0;j<M;j++){
				int d; cin >> d;
				cnt[d]++;
			}
		}
		int res = 0;
		for(int i=0;i<=100;i++){
			if(cnt[res] < cnt[i]) res = i;
		}
		cout << (cnt[res] >= Q ? res : 0) << endl;
	}
}