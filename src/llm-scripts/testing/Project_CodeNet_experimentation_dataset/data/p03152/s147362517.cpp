#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, M; cin >> N >> M;
    int A[N]; rep(i, N) cin >> A[i];
    int B[M]; rep(j, M) cin >> B[j];
    sort(A, A+N); reverse(A, A+N);
    sort(B, B+M); reverse(B, B+M);
    int idx_A = 1, idx_B = 1;
    ll ans;
    rep(i, N-1){
        if(A[i] == A[i+1]){
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i, M-1){
        if(B[i] == B[i+1]){
            cout << 0 << endl;
            return 0;
        }
    }

    if(A[0] == B[0] && A[0] == N*M){
        ans = 1;
        ll op = N*M-1;
        ll tate = 1, yoko = 1;
        ll kouten = 1, put_kouten = 1;
        while(idx_A < N || idx_B < M){
            if(idx_A == N){
                if(op > B[idx_B]){
                    ans = (ans * (kouten-put_kouten)) % mod;
                    put_kouten++;
                }
                else{
                    kouten += yoko; tate++;
                    ans = (ans * yoko) % mod;
                    put_kouten++;
                    idx_B++;
                }
            }
            else if(idx_B == M){
                if(op > A[idx_A]){
                    ans = (ans * (kouten-put_kouten)) % mod;
                    put_kouten++;
                }
                else{
                    kouten += tate; yoko++;
                    ans = (ans * tate) % mod;
                    put_kouten++;
                    idx_A++;
                }
            }
            else{
                if(op > A[idx_A] && op > B[idx_B]){
                    ans = (ans * (kouten-put_kouten)) % mod;
                    put_kouten++;
                }
                else if(op == A[idx_A] && op == B[idx_B]){
                    //一意に決まる
                    kouten += tate; yoko++;
                    kouten += yoko; tate++;
                    put_kouten++;
                    idx_A++; idx_B++;
                }
                else if(op == A[idx_A]){
                    kouten += tate; yoko++;
                    ans = (ans * tate) % mod;
                    put_kouten++;
                    idx_A++;
                }
                else{
                    kouten += yoko; tate++;
                    ans = (ans * yoko) % mod;
                    put_kouten++;
                    idx_B++;
                }
            }
            op--;
        }
        //1以上op以下の数は好きなとこにおける -> ans *= fac[op];
        ll fac[op+1]; fac[0] = 1;
        rep(i, op){
            fac[i+1] = (fac[i]*(i+1)) % mod;
        }
        ans = (ans * fac[op]) % mod;
    }
    else{
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}