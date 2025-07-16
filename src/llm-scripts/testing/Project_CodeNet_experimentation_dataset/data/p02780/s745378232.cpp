#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    v1 a(1001, 0);
    for(int i = 1; i <1001; i++){
        a[i] = a[i-1] + i;
    }
    int n, k;
    cin >> n >> k;
    vector<double> q(n+1, 0);
    q[0] = 0;
    for(int i = 1; i<=n; i++){
        int p; 
        cin >> p;
        double sum = static_cast<double>(a[p]) / static_cast<double>(p) + q[i-1];
        q[i] = sum;
    }
    int j = 0;
    double ans = 0;
    for(int i = k; i <= n; i++){
        ans = max(ans, q[i]-q[j]);
        j++;
    }
    cout <<fixed << setprecision(15) <<  ans << endl;


}