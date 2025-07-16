#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

int main(){

    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    

    sort(all(a));
    if(a.at(n-1) < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } 
    int temp = a.at(0);
    rep(i,n-1){ 
        temp = __gcd(temp,a.at(i+1)); 
        if(temp == 1){
            cout << "POSSIBLE" << endl;
            return 0;
        } 
    }
    if(k%temp == 0){
        cout << "POSSIBLE" << endl;
        return 0;
    } 
    else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

}
