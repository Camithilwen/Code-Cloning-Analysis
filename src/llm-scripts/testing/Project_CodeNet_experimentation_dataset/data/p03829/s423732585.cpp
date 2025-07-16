#include<iostream>
#include<vector>
using namespace std;

int main(){
    long N, A, B;
    cin >> N >> A >> B;
    vector<long> X(N);
    for (int i=0; i<N; i++){
        cin >> X[i];
    }
    long ans = 0;
    for (int i=0; i<N-1; i++){
        if ((X[i+1]-X[i]) * A < B){
            ans += (X[i+1]-X[i]) * A;
        }
        else ans += B;
    }
    cout << ans << endl;
    return 0;
}