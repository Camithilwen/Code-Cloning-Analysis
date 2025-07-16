#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    int n,m;
    int s[6];
    char c[6];
    cin >> n >> m;
    rep(i,m)cin >> s[i] >> c[i];
    bool ok =false;

        rep(i,1000){
            string now = to_string(i);
            if(now.size()==n){
                ok = true;
                rep(j,m){
                    if(now[s[j]-1]!=c[j]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                cout << stoi(now);
                return 0;
            }
        }

    cout << -1;

    return 0;
}