#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<vector<double>>> dp;
int n;

double find(int i, int j, int k){

    if(dp[i][j][k]!=-1) return dp[i][j][k];
 
    dp[i][j][k] = 0.0;
    if(i==0 && j==0 && k==0){
        return dp[i][j][k];
    }
    dp[i][j][k] += n;
    if(k){
        dp[i][j][k] += k*find(i,j+1,k-1);
    }
    if(j){
        dp[i][j][k] += j*find(i+1,j-1,k);
    }
    if(i){
        dp[i][j][k] += i*find(i-1,j,k);
    }
    dp[i][j][k] /= 1.0*(i+j+k);
    return dp[i][j][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        cin >> n;
        dp = vector<vector<vector<double>>> (n+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
        
        vector<int> count(4,0);
        for(int i=0 ; i<n ; i++){
            int in;
            cin >> in;
            count[in]++;
        }
        cout.precision(16);
        cout << find(count[1],count[2],count[3]) << "\n";
    }
    return 0;
}

