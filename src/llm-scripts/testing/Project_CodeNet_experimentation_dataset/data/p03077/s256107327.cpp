#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> a(5);
    for(int i = 0; i < 5; i++) cin >> a[i];
    long long b = 1e17;
    for(int i = 0; i < 5; i++) b = min(b, a[i]);
    long long t = (N + b - 1) / b;
    long long ans = 5 + t - 1;
    cout << ans << endl;
}