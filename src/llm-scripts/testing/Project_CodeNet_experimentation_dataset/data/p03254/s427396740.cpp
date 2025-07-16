#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    int N;
    long long x;
    cin >> N >> x;
    vector<long long> cost(N);
    long long sum = 0;
    for(int i=0; i<N; i++){
        cin >> cost[i];
        sum += cost[i];
    }

    if(sum == x){
        cout << N << endl;
        return 0;
    }

    sort(cost.begin(), cost.end());

    int k = 0;
    long long tmp_sum = 0;
    while(k < N){
        tmp_sum += cost[k];
        
        if(tmp_sum > x){
            cout << k << endl;
            return 0;
        }

        k += 1;
    }

    cout << N-1 << endl;
    return 0;

}
