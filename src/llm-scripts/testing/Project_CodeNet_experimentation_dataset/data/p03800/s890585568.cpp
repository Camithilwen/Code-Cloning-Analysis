#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=(s[i]=='o');
    for(int ti=0;ti<2;ti++){
        for(int tj=0;tj<2;tj++){
            vector<int> b(n);
            b[0]=ti,b[1]=tj;
            for(int i=0;i<n;i++){
                int j=(i+1)%n;
                b[(i+2)%n]=b[i]^b[j]^a[j];
            }
            if(b[0]==ti&&b[1]==tj){
                string ans="";
                for(int i=0;i<n;i++) ans+="WS"[b[i]];
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}