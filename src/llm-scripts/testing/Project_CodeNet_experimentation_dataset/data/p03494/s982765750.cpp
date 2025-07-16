#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    vector<int> data(N);
    for (int i=0; i<N; i++) {
        cin >> data.at(i);
    }

    int count = 0;
    while (true) {
        for (int j=0; j<N; j++) {
            if (data.at(j)%2 != 0) {
                cout << count << endl;
                exit(0);
            }
            data.at(j) /= 2;
        }
        count++;
    }
}