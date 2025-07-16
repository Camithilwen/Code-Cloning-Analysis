#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 300 + 9;
const ll inf = 1e6 + 7;
typedef pair<ll,ll> LL;

ll t,n,a[N],i,j;
string s;
bool chk(){
    vector<ll> v;
    v.push_back(0);
    for (i = n;i >= 1;i--){
        ll p = a[i];
        for (auto j : v) p = min(p,p^j);
        if (p){
            if (s[i] == '1') return true;
            v.push_back(p);
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>t;
    while(t--){
        cin>>n;
        for (i = 1;i <= n;i++) cin>>a[i];
        cin>>s; s = " " + s;
        cout<<chk()<<"\n";
    }
}
