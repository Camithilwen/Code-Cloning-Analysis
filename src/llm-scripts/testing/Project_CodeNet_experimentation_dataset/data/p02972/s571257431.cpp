#include <iostream>
#include <vector>
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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for(int i = 1; i < N + 1; i++) cin >> a[i];
    vector<int> sum(N + 1, 0);
    vector<int> ko(N + 1, 0);
    int cnt = 0;
    for(int i = N; i > 0; i--){
        if(sum[i] % 2 != a[i]){
            ko[i]++;
            sum[i]++;
            cnt++;
            vector<long long> d = divisor(i);
            for(int j = 0; j < d.size(); j++){
                if(d[j] != i){
                    sum[d[j]]++;
                }
            }
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= N; i++){
        if(ko[i] == 1){
            cout << i << endl;
        }
    }
}