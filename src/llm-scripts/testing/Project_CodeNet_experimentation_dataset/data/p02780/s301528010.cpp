#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    double ans = 0;
    cin >> N >> K;
    vector<double> p(N), E(N), sumE(N, 0);
    for(int i = 0; i < N; ++i)cin >> p[i];
    double bufe = 0;
    for(int i = 0; i < N; ++i){
        E[i] = (1/p[i])*(p[i]*(p[i]+1)/2);
    }
    for(int i = 0; i < N; ++i){
        if(i == 0){
            for(int i = 0; i < K; ++i) sumE[0] += E[i];
        }
        else if(i+K-1 < N)sumE[i] = sumE[i-1] - E[i-1] + E[i+K-1];
        else break;
    }
    sort(sumE.begin(), sumE.end(), greater<double>());
    cout << setprecision(16) << sumE[0] << endl;
    return 0;
}