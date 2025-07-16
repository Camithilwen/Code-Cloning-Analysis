#include<bits/stdc++.h>
using namespace std;

int A, B, C, D, E, K;
vector<int> a;

int main() {
    cin >> A >> B >> C >> D >> E >> K;
    a.push_back(A); a.push_back(B); a.push_back(C); a.push_back(D); a.push_back(E);
    bool istrue = true;
    for (int i=0; i<a.size(); i++) {
        for (int j=i+1; j<a.size(); j++) {
            if (abs(a[i] - a[j]) > K) { istrue = false; break; }
        }
    }
    istrue ? cout << "Yay!\n" : cout << ":(\n";
    return 0;
}
