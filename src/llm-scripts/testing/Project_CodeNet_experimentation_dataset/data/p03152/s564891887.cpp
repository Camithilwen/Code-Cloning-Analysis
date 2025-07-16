#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(RALL(a));
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(RALL(b));
    LL h=0,w=0;
    LL ans = 1, res = 0;
    for (int i = n*m; i >= 1; i--) {
        if(h < n && i == a[h] && w < m && i == b[w]){
            h++;
            w++;
            res += h + w - 2;
        }
        else if(h < n && i == a[h]){
            if(w==0) ans = 0;
            h++;
            res += w - 1;
            ans = ans * w % mod;
        }
        else if(w < m && i == b[w]){
            if(h==0) ans = 0;
            w++;
            res += h - 1;
            ans = ans * h % mod;
        }
        else{
            if(res <= 0) ans = 0;
            ans = ans * res % mod;
            res--;
        }
    }
    cout << ans << endl;
    return 0;
}
