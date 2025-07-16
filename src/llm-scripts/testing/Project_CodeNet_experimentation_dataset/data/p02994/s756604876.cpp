#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, l;
    cin >> n >> l;

    long long n_sum = n*l + n*(n-1)/2;

    long long min_delta = 1e12;
    long long minv;

    for(long long i = 0; i < n; i++){
        long long sum = n_sum - (l+i);
        if(min_delta > abs(n_sum - sum)){
            min_delta = abs(n_sum - sum);
            minv = sum;
        }
    }
    cout << minv << endl;
    return 0;
}