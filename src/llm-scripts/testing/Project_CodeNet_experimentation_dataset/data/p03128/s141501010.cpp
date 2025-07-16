#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int INF = -1e9;
    vector<int> dpk(N + 1, INF), A(M);
    for(int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> cost(M);
    for(int i = 0; i < M; i++){
        if(A[i] == 1) cost[i] = 2;
        else if(A[i] == 2 || A[i] == 3 || A[i] == 5) cost[i] = 5;
        else if(A[i] == 4) cost[i] = 4;
        else if(A[i] == 6 || A[i] == 9) cost[i] = 6;
        else if(A[i] == 7) cost[i] = 3;
        else cost[i] = 7;
    }
    dpk[0] = 0;
    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < M; j++){
            if(i - cost[j] >= 0) dpk[i] = max(dpk[i], dpk[i - cost[j]] + 1);
        }
    }
    int keta = dpk[N];
    vector<int> ke(keta);
    int i = 0;
    while(N > 0){
        for(int j = M - 1; j >= 0; j--){
            if(N - cost[j] >= 0 && dpk[N] == dpk[N - cost[j]] + 1){
                ke[i] = A[j];
                i++;
                N -= cost[j];
                break;
            }
        }
    }
    for(int i = 0; i < keta; i++){
        cout << ke[i];
    }
    cout << endl;
}