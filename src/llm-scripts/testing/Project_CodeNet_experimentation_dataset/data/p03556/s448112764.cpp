#include <bits/stdc++.h>
using namespace std;

bool is_squere(long N) {
        long r = (long) floor(sqrt(N));
        return (r * r) == N;
}

int main() {
    int N;
    cin >> N;


    for(int i = N; i > 0; i--) {
        if(is_squere(i)) {
            cout << i << endl;
            return 0;
        }
    }
}