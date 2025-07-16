#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<int>x(N);
    vector<int>y(M);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x[N-1] < y[0]) {
        if(y[0] > X && x[N-1] < Y) {
            cout << "No War" << endl;
            return 0;
        } 
    }
    cout << "War" << endl;
}