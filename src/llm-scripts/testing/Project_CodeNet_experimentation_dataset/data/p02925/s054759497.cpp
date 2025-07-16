#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<queue<int>> Q(N + 1);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N - 1; j++){
			int A;
			cin >> A;
			A--;
			Q[i].push(A);
		}
		Q[i].push(N);
	}
	Q[N].push(N);
	int ans = 0;
	int cnt = N * (N - 1);
	bool ok = true;
	vector<int> upd;
	for (int i = 0; i < N; i++){
		upd.push_back(i);
	}
	while (cnt > 0){
		ans++;
		vector<int> upd2;	
		for (int i : upd){
			if (Q[Q[i].front()].front() == i && Q[i].front() > i){
				upd2.push_back(i);
				upd2.push_back(Q[i].front());
			}
		}
		for (int i : upd2){
			Q[i].pop();
			cnt--;
		}
		if (upd2.empty()){
			ok = false;
			break;
		}
	}
	if (!ok){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}