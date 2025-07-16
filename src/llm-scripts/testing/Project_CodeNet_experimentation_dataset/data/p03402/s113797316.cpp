#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main(void) {
    int A, B;
    cin >> A >> B;
    cout << 100 << " " << 100 << endl;
    vector< vector<int> > grad(100, vector<int>(100));
    for(int i=0; i<50; i+=2) {
        for(int j=0; j<100; j+=2) {
            if(A > 1) {
                grad[i][j] = 1;
                --A;
            }
        }
    }
    for(int i=50; i<100; i++) {
        for(int j=0; j<100; j++) {
            grad[i][j] = 1;
            if(B > 1 && i>50 && i%2 == 1 && j%2) {
                grad[i][j] = 0;
                --B;
            }
        }
    }
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(grad[i][j]) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    return 0;
}
