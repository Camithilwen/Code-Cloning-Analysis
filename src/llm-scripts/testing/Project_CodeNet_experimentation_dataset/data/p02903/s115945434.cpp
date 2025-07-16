#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    rep(i,h){
        bool rev_fl = i<b;
        rep(j,w){
            if(j<a){
                if(rev_fl) cout << 1;
                else cout << 0;
            }else {
                if(rev_fl) cout << 0;
                else cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}