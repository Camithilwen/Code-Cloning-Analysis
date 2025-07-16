#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++){
        for (int k = 0; k < B.size(); k++){
            for (int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    int n, l;
    cin >> n >> l;
    int sm = 0;
    int ans = 1000000;
    rep(i, n){
        sm += l + i;
    }
    // cout << sm << endl;
    rep(i, n){
        int sm_ = 0;
        rep(j, n){
            if(i == j) continue;
            sm_ += l + j;
        }
        if(abs(ans - sm) > abs(sm_ - sm)) ans = sm_;
    }
    cout << ans << endl;
}