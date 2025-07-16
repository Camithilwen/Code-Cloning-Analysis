#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> A;
    A.push_back(0);
    rep(i,n){
        int a; cin >> a;
        A.push_back(a);
    }
    A.push_back(0);
    int sum = 0;
    rep(i,n+1) sum += abs(A[i+1] - A[i]);
    for(int i = 1; i <= n; i++){
        int ans = sum;
        ans -= abs(A[i] - A[i-1]);
        ans -= abs(A[i+1] - A[i]);
        ans += abs(A[i+1] - A[i-1]);
        cout << ans << endl;
    }
}