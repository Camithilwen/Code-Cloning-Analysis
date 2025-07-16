#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string s = to_string(N);
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    if (N % sum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
