#include <iostream>
#include <math.h>
using namespace std;

int main() {

    long N;

    cin >> N;

    // N = A * B
    // B = N / A
    
    // A , B 桁数大きい方の、最小値
    long ans = 100000000;

    double d = sqrt(N) + 1;
    //cout << "d: " << d << endl;

    for (long i = 1; i < d ; i++) {
        long a = i;

        //整数チェック
        if (N % a != 0){
            continue;
        }
        long b = N / a;

        //cout << "a: " << a << "   b: " << b << endl;
        string s_a = to_string(a);
        int k_a = s_a.size();
        string s_b = to_string(b);
        int k_b = s_b.size();

        int m = max(k_a, k_b);

        if (ans > m){
            ans = m;
        }
    }

    cout << ans << endl;

    return 0;

}