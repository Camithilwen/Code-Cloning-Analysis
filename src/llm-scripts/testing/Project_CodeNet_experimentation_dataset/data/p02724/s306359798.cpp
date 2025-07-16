#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int x;
    cin >> x;
    int happy = 0;
    happy += (x / 500) * 1000;
    happy += ((x % 500) / 5) * 5;
    cout << happy << endl;
}