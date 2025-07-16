#include<iostream>
using namespace std;

int main(void) {
    string N; cin >> N;
    bool is7 = false;
    for (int i = 0; i < N.size(); i++) {
        if (N[i] == '7') {
            is7 = true;
        }
    }
    if (is7) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
