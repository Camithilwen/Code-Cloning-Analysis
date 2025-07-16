#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define vi vector<int>
#define Sort(v) sort(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int maxn = -1000000 , minn=1000000;
    long long sum=0;
    rep(i,n){
        int a; cin >> a;
        
        sum += a;
        maxn = max(maxn,a);
        minn = min(minn,a);
    }
    
    cout << minn << " " << maxn << " " <<sum << endl;
}






