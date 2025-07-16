#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n, l ;
    cin >> n >> l ;
    vector<int> vec (n) ;
    rep(i, n) vec[i] = i + 1 ;
    rep(i , n){
        vec[i] = vec[i] + l - 1 ;
    }
    int t = 200000 ;
    int num ; 
    rep(i, n){
        if(t > abs(vec[i])){
            t = abs(vec[i]) ;
            num = i ;
        }
    }
    int tot = 0;
    rep(i, n){
        if(i == num){
            continue ;
        }
        else {
            tot += vec[i] ;
        }
    }
    cout << tot << endl ;
}