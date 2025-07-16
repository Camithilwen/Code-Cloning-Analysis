#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int A,B,K;
    cin >> A >> B >> K;

    rep(i,K)
        if(i%2) {
            if(B%2)
                --B;
            B /= 2;
            A += B;
        } else {
            if(A%2)
                --A;
            A /= 2;
            B += A;
        }
    
    cout << A << " " << B << endl;
}