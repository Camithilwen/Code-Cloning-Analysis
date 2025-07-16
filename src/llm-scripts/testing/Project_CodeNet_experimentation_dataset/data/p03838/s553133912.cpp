#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    int X,Y;
    cin >> X >> Y;
    int ans = 2e9+1;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++){
        int x = (i? -X:X),y = (j? -Y:Y);
        if(x<=y) ans = min(ans,i+j+y-x);
    }
    cout << ans << "\n";
}