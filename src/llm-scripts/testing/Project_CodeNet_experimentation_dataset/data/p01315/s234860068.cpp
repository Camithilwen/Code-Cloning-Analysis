#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    while( cin >> N , N ){
        string L[50];
        int P[50], A[50], B[50], C[50], D[50], E[50], F[50], S[50], M[50];
        vector< pair<double, string> > ans(N);

        for(int i = 0; i < N; i++){
            int time = 0, value = 0;
            cin >> L[i] >> P[i] >> A[i] >> B[i] >> C[i] >> D[i] >> E[i] >> F[i] >> S[i] >> M[i];
            ans[i].second = L[i];
            time = A[i] + B[i] + C[i] + (D[i] + E[i]) * M[i];
            value = M[i] * F[i] * S[i] - P[i];
            ans[i].first = -value / (double)time;
        }

        sort(ans.begin(), ans.end());
        for(int i = 0;  i< N; i++){
            cout << ans[i].second << endl;
        }
        cout << "#" << endl;

    }
    return 0;
}