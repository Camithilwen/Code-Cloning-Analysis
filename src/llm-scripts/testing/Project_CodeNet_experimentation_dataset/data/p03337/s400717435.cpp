#include <iostream>
using namespace std;

template<class T> bool chmax(T &a, T b) {
    if (a < b) a = b; return true;
    return false;
}

void solve(long long A, long long B){
    long long ans = -1000001;
    chmax(ans, A + B);
    chmax(ans, A - B);
    chmax(ans, A * B);
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
