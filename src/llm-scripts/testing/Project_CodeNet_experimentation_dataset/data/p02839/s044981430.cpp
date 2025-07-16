#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;
template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}
template<typename T>
void cout_mat(vector<vector<T>  > &mat){
    for(int i=0; i<mat.size(); i++){
        vector<T> vec = mat[i];
        cout_vec(mat[i]);
    }
}

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<int>> grid(H,vector<int>(W,0));
    for(auto &line:grid){
        for(auto &a:line){
            cin >> a;
        }
    }

    for(auto &line:grid){
        for(auto &a:line){
            int x;
            cin >> x;
            a-=x;
        }
    }
    int N=160*160;

    vector<vector<vector<int>>> dp(H+1,vector<vector<int>>(W+1,vector<int>(N+1,0)));
    dp[0][0][N/2]=1;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int diff=grid[i][j];
            for(int k=0; k<=N; k++){
                if(0<=k+diff && k+diff<=N){
                    dp[i+1][j][k+diff]|=dp[i][j][k];
                    dp[i][j+1][k+diff]|=dp[i][j][k];
                }
                if(0<=k-diff && k-diff<=N){
                    dp[i][j+1][k-diff]|=dp[i][j][k];
                    dp[i+1][j][k-diff]|=dp[i][j][k];
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        if(dp[H][W-1][N/2-i] || dp[H][W-1][N/2+i]){
            cout << i << endl;
            return 0;
        }
    }

}