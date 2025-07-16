#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
const int N = 3e5 + 1;
int n, m, k;
long long int A[N], B[N], cs[N], sum; 
int main(){
    ll H , W , N ;
    cin >> H >> W >> N ;
    if(N % max(H , W ) == 0) cout << N / max(H , W ) << endl;
    else cout <<  ( N / max(H , W ) ) + 1 << endl;
    return 0;
}