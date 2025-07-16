#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    vector<int> A(5);
    for(int i = 0; i < 5; i++){
        cin >> A[i];
    }
    int k;
    cin >> k;
    sort(all(A));
    if(A[4]-A[0] <= k) puts("Yay!");
    else puts(":(");
}
