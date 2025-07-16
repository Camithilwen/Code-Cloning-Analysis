#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> AC;
    AC.push_back(0);

    //入力
    vector<int> X(Q), Y(Q);
    for(int i=0; i<Q; i++) {
        int a,b;
        cin >> X[i] >> Y[i];
    }

    //Sの"AC"をカウントして存在した位置をvectorにpush_back
    int count = 0;
    for(int i=1; i<N; i++) {
        if(S[i-1] == 'A' && S[i] == 'C'){
            count++;
        }
        AC.push_back(count);
    }

    for(int i=0; i<Q; i++) {
        cout << AC[Y[i]-1] - AC[X[i]-1] << endl;
    }
}