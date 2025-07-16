#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    int n, q ;
    string s ;
    cin >> n >> q ;
    cin >> s ; 
    vector<int> l (q), r(q) ;
    rep(i, q){
        cin >> l[i] >> r[i] ;
        l[i]-- ;
        r[i]-- ;
    }
    vector<int> num (n) ;
    rep(i, n - 1){
        if(s[i] == 'A' && s[i + 1] == 'C'){
            num[i + 1]++ ; 
        }
    }
    for(int i = 1 ; i < n ; i++){
        num[i] += num[i - 1] ;
    }
    vector<int> ans ;
    rep(i, q){
        ans.push_back(num[r[i]] - num[l[i]]) ;
    }
    rep(i, q){
        cout << ans[i] << endl ; 
    }
}

