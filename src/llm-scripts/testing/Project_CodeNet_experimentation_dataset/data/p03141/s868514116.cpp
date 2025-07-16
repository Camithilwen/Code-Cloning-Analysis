#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> s(N);
    long long ans = 0;
    for(int i = 0; i < N; i++){
        long long a, b;
        cin >> a >> b;
        ans -= b;
        s[i] = a + b;
    }
    sort(s.begin(), s.end());
    int f = 0;
    for(int i = 0; i < N; i++){
        if(f % 2 == 0) ans += s[N - 1 - i];
        f++;
    }
    cout << ans << endl;
}