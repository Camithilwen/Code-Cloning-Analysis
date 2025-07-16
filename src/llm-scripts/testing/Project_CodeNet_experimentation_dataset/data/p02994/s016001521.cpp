#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, L;
    cin >> N >> L;
    vector<int> as(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        as[i] = L + i;
        sum += as[i];
    }
    if(as[0] * as[N - 1] <= 0){
        cout << sum << endl;
        return 0;
    }
    if(as[N - 1] < 0){
        cout << sum - as[N - 1] << endl;
        return 0;
    }
    cout << sum - as[0] << endl;
}