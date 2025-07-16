#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<long long> divisor(long long n){//nの約数列挙
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> v = divisor(M);
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(M / v[i] >= N) ans = max(ans, v[i]);
    }
    cout << ans << endl;
}