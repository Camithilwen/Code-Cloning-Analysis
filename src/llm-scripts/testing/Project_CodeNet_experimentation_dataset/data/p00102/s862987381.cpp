#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

int matrix[16][16];

int main(){
    int n,i,j;

    while( cin >> n, n ){
        // input
        rep(i,n) rep(j,n) cin >> matrix[i][j];

        // yoko
        rep(i,n){
            int yoko = 0;
            rep(j,n) yoko += matrix[i][j];
            matrix[i][n] = yoko;
        }

        // tate
        rep(j,n){
            int tate = 0;
            rep(i,n) tate += matrix[i][j];
            matrix[n][j] = tate;
        }

        int sum = 0;
        rep(i,n) sum += matrix[i][n];
        matrix[n][n] = sum;

        // output
        rep(i,n+1){
            rep(j,n+1){
                printf("%5d",matrix[i][j]);
            }
            puts("");
        }
    }

    return 0;
}