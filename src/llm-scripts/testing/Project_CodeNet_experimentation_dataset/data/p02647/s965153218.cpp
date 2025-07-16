#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i=0; i<(int64_t)(n); i++)
#define all(v) v.begin(), v.end()
//c
int main(){

    int n, k;cin >> n >> k;
    vector<vector<int>> a(51, vector<int>(n));
    rep(i, n) cin >> a[0][i];

    rep(i, k){

        vector<int> memo(n+1);

        rep(j, n){
            int min, max;
            min=j-a[i][j];
            max=j+1+a[i][j];
            if(min<0) min=0;
            if(max>n) max=n;
            memo[min]++;
            memo[max]--;
        }

        int cnt=0;

        rep(j, n){
            cnt+=memo[j];
            a[i+1][j]=cnt;
        }

        bool fin=true;

        rep(j, n){
            if(a[i][j]!=a[i+1][j]) fin=false;
        }

        if(fin){
            k=i+1;
            break;
        }

    }

    rep(j, n-1){
        cout << a[k][j] << " ";
    }
    cout << a[k][n-1] << endl;

    return 0;

}