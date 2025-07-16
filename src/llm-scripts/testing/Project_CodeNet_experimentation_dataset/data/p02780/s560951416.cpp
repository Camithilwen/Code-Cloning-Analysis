#include<bits/stdc++.h>
#include<iomanip>
using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    vector<float> p(N);
    for(int i=0; i<N; i++) cin >> p.at(i);
    for(int i=0; i<N; i++) p.at(i) = (p.at(i) + 1) / 2;
    vector<double> q(N);
    q.at(0) = p.at(0);
    for(int i=1; i<N; i++) q.at(i) = q.at(i-1) + p.at(i);
    vector<double> r(N - K + 1);
    r.at(0) = q.at(K-1);
    for(int i=1; i<N-K+1; i++){
        r.at(i) = q.at(i+K-1) - q.at(i-1);
    }
    double max = 0;
    for(int i=0; i<N-K+1; i++){
        if(max < r.at(i)) max = r.at(i);
    }
    cout << fixed << setprecision(12);
    cout << max << endl;
}
