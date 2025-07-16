#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; string A, B, C; cin >> N >> A >> B >> C;
    ll c = 0;
    for(int i=0; i<N; i++){
        if(A[i] == B[i]&&B[i] ==C[i]){}
        else if(A[i] == B[i]&&B[i] !=C[i]){c++;}
        else if(A[i] != B[i]&&B[i] ==C[i]){c++;}
        else if(A[i] == C[i]&&B[i] !=C[i]){c++;}
        else{c += 2;}
    }
    cout << c;
}