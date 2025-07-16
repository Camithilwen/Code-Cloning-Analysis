#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    long long ans=0,n,a,b;
    cin>>n>>a>>b;
    vector<long long>p(n);
    rep(i,n)cin>>p[i];
    rep(i,n-1){
        ans+=min(a*(p[i+1]-p[i]),b);
    }
    cout<<ans;
	return 0;
}
