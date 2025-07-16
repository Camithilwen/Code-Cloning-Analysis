#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int M = 1e9+7 ;

const ll INF = 1e18 ;




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    cin  >>  N;

    vector<vector<int>> A(N, vector<int>(2));

    for (int i = 0; i < N; ++i) {
        cin >> A[i][0] >> A[i][1];
    }

    auto comp = [&](vector<int>& a, vector<int>& b) {
        return a[0] + a[1] < b[0] + b[1];
    };

    sort(A.begin(), A.end(), comp);

    vector<vector<ll>> dp (N+1 , vector<ll> (N+1, INF)); 

    



    for(int i = 0 ; i <= N; ++i){

        dp[i][0] = 0 ;
    }

    for(int i = 1 ; i <= N; ++i){
        for(int j = 1 ; j <= i ; ++j ){
            dp[i][j] = dp[i-1][j]; 
            if (A[i-1][0] >= dp[i-1][j-1]){
                dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + A[i-1][1]);
            }
        }
    }


    for(int j = N ;  j >= 0; --j){
        if (dp[N][j] != INF){
            cout <<  j << "\n"; 
            break; 
        }
    }

    



    
  
    return 0;
}

