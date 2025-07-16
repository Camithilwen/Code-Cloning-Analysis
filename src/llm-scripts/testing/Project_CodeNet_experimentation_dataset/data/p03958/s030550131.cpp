#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//A=65,a=97

int main() {
    int k,t;cin >> k >> t;
    vector<int> a(t);for(int i=0;i<t;i++) cin >> a[i];
    sort(a.begin(),a.end());
    if(a[t-1]<=(k+1)/2){
        cout << 0 << endl;
        return 0;
    }

    a[t-1] -= k-a[t-1];
    cout << a[t-1]-1 << endl;

    return 0;
}