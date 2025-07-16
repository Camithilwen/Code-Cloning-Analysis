#include <iostream>
#include <vector>

using namespace std;

vector<int> permMul(const vector<int>& a, const vector<int>& b){
    vector<int> res(a.size());
    for(int i=0;i<a.size();i++) res[i] = a[b[i]];
    return res;
}

vector<int> permPow(const vector<int>& p, long long K){
    if(K == 0){
        vector<int> res = p;
        for(int i=0;i<res.size();i++) res[i] = i;
        return res;
    }
    vector<int> half = permPow(p, K/2);
    vector<int> res = permMul(half, half);
    if(K%2 == 1) res = permMul(res, p);
    return res;
}

int main(){
    int N;
    while(cin >> N){
        vector<long long> x(N);
        for(auto& t : x) cin >> t;
        vector<long long> d(N-1);
        for(int i=0;i<N-1;i++) d[i] = x[i+1] - x[i];
        int M; long long K;
        cin >> M >> K;
        vector<int> s(N-1);
        for(int i=0;i<N-1;i++) s[i] = i;
        for(int i=0;i<M;i++){
            int a; cin >> a;
            swap(s[a-2], s[a-1]);
        }
        cout << x[0] << endl;
        s = permPow(s, K);
        for(int i=1;i<N;i++){
            x[i] = x[i-1] + d[s[i-1]];
            cout << x[i] << endl;
        }
    }
}