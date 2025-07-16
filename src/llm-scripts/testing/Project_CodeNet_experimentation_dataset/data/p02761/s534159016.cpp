#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int M = 0;
    cin >> M;
    vector<int> s(M,0);
    vector<int> c(M,0);
    if(M == 0) {
        cout << (int)pow(10, N - 1)*(N != 1) << endl;
        return 0;
    }
    for(int i = 0; i < M; i++) {
        cin >> s.at(i);
        cin >> c.at(i);
    }
    for(int i = pow(10, N - 1)*(N != 1); i < pow(10, N); i++) {
        int check = 1;
        for(int j = 0; j < M; j++) {
            if((i/(int)pow(10, N - s.at(j)))%10 == c.at(j)) {
                continue;
            }
            check = 0;
        }
        if(check) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;


    return 0;
}