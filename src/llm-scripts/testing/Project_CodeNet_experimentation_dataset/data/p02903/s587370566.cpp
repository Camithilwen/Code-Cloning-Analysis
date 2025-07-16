#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll h,w,a,b;
    cin >> h >> w >> a >> b;
    if(h == 1){
        for(i = 0;i < a;++i) cout << 0;
        for(i = a;i < w;++i) cout << 1;
        cout << endl;
        return 0;
    }else if(w == 1){
        for(i = 0;i < b;++i){
            cout << 0 << endl;
        }
        for(i = b;i < h;++i){
            cout << 1 << endl;
        }
        return 0;
    }
    for(i = 0;i < h;++i){
        for(j = 0;j < w;++j){
            if(i < b && j < a) cout << 0;
            else if(i >= b && j >= a) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }

    return 0;
}