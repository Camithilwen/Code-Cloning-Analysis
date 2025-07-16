#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end(), greater<long long>());
    return ret;
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> ret;
    ret = divisor(m);
    long long ans = 1;
    for(long long i = 0; i < ret.size(); i++){
        if(m/ret[i] >= n){
            ans = ret[i];
            break;
        }
    }

    cout << ans << endl;
    return 0;
}