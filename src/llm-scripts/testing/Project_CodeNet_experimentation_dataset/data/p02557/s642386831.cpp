#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    map<int,int> mpa;
    map<int,int> mpb;
    rep(i,N){
        mpa[A[i]]++;
        mpb[B[i]]++;
    }
    vector<int> a(N + 1, 0);
    vector<int> b(N + 1, 0);
    rep(i,N){
        a[A[i]] = i + 1;
    }
    rep(i,N){
        b[B[i]] = i + 1;
    }
    rep(i,N){
        a[i + 1] = max(a[i + 1], a[i]);
        b[i + 1] = max(b[i + 1], b[i]);
    }
    cout << endl;
    int max_sum = 0;
    int max_pointer = 1;
    for (int i = 1; i <= N; i++){
        if (max_sum < mpa[i] + mpb[i]){
            max_sum = mpa[i] + mpb[i];
            max_pointer = i;
        }
    }
    bool possible = true;
    vector<int> C(N);
    if (max_sum > N){
        possible = false;
    }
    else{
        int zurashi = -1 * N;
        rep(i,N){
            zurashi = max(zurashi, a[i + 1] - b[i]);
        }
        rep(i,N){
            C[(i + zurashi) % N] = B[i];
        }
    }
    if (!possible) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        rep(i,N){
            cout << C[i] << " ";
        }
        cout << endl;
    }
}