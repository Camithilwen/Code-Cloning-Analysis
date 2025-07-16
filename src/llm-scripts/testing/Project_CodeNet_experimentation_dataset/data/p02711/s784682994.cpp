#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    char a;
    bool contain = false;
    rep(i, 3){
        cin >> a;
        if(a == '7'){
            contain = true;
        }
    }

    if(contain) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}