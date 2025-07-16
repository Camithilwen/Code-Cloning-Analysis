#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int left = A + B;
    int right = C + D;
    if (left > right) {
        cout << "Left" << endl;
    } else if (left < right) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }
    return 0;
}