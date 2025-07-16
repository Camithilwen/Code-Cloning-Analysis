#include<bits/stdc++.h>

using namespace std;

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;

    vector<int> L(M), R(M);

    for(int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }

    vector<vector<int>> train(N, vector<int>(N, 0));
    vector<vector<int>> train_cum(N+1, vector<int>(N+1, 0));

    for(int i = 0; i < M; i++) {
        train[L[i]][R[i]] += 1;
    }

    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            train_cum[i+1][j+1] = train_cum[i][j+1] + train_cum[i+1][j] - train_cum[i][j] + train[i][j];
        }
    }
    
    int p, q;
    vector<int> answer;

    for(int k = 0; k < Q; k++) {
        cin >> p >> q;

        answer.push_back(train_cum[q][q] - train_cum[p-1][q] - train_cum[q][p-1] + train_cum[p-1][p-1]);
    }

    for(auto i : answer) {
        cout << i << endl;
    }

	return 0;
}