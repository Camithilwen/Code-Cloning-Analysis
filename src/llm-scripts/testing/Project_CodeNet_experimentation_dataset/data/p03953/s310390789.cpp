#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

vec<int> mult(vec<int>& A,vec<int>& B){
    vec<int> C(A.size());
    for(int i=0;i<A.size();i++) C[i] = B[A[i]];
    return C;
}

vec<int> pow(vec<int>& A,ll n){
    if(n==1) return A;
    vec<int> R = pow(A,n>>1);
    R = mult(R,R);
    if(n&1) R = mult(A,R);
    return R;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<int> X(N);
    vec<int> D(N-1);
    for(int i=0;i<N;i++){
        cin >> X[i];
        if(i) D[i-1] = X[i]-X[i-1];
    }
    vec<int> perm(N-1);
    iota(perm.begin(),perm.end(),0);
    int M;
    ll K;
    cin >> M >> K;
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        a -= 2;
        swap(perm[a],perm[a+1]);
    }
    auto res = pow(perm,K);
    ll s = X[0];
    for(int i=0;i<N;i++){
        cout << s << "\n";
        if(i!=N-1) s += D[res[i]];
    }
}