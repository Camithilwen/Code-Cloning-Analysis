#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N;
string S;
int Q;
int k[100];
ll D[1000010];
ll M[1000010];
ll C[1000010];
ll sum[1000010];
ll ans[100];

void input(){
    cin >> N >> S >> Q;
    for(int i = 0; i < Q; i++){
        cin >> k[i];
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        if(S[i] == 'M') M[i]++;
        M[i + 1] = M[i];
        if(S[i] == 'C') C[i]++;
        C[i + 1] = C[i];
    }

    for(int i = 1; i < N; i++){
        sum[i] = sum[i - 1];
        if(S[i] == 'C') sum[i] += M[i];
    }

    for(int i = 0; i < Q; i++){
        for(int j = 0; j < N; j++){
            if(S[j] != 'D') continue;
            int nd = min(j + k[i] - 1, N - 1);
            ll res = sum[nd] - sum[j] - M[j] * (C[nd] - C[j]);
            ans[i] += res;
        }
    }
}

void output(){
    for(int i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    input();
    solve();
    output();
    return 0;
}