#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A[300];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int a;
            cin >> a;
            A[i].push_back(a-1);
        }
        reverse(A[i].begin(), A[i].end());
    }
    int ans = 1e9;
    bitset<300> removed;
    int rem = 0;
    while(rem < M){
        vector<int> num(M);
        for(int i=0; i<N; i++){
            while(removed[A[i].back()]) A[i].pop_back();
            num[A[i].back()]++;
        }
        int mx = max_element(num.begin(), num.end()) - num.begin();
        ans = min(ans, num[mx]);
        removed[mx] = 1;
        rem++;
    }
    cout << ans << endl;
}