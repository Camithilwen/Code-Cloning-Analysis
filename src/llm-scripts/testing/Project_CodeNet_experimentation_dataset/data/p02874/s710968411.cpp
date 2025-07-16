#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 1e5 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

ll n,i,mx[N],p,q,maxx,cur;
LL a[N],b[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    q = n + 1; a[q].sc = inf;
    cin>>n;
    for (i = 1;i <= n;i++){
        cin>>a[i].fs>>a[i].sc;
        a[i].sc++;
        maxx = max(maxx,a[i].sc - a[i].fs);
        if (a[i].fs > a[p].fs) p = i;
        if (a[i].sc < a[q].sc) q = i;
    }
    p = a[p].fs; q = a[q].sc;
    ll ans = maxx + max(0ll,q - p);
    for (i = 1;i <= n;i++){
        b[i].fs = max(0ll,a[i].sc - p);
        b[i].sc = q - a[i].fs;
    }
    sort(b + 1,b + n + 1);
    for (i = n;i >= 1;i--) mx[i] = max(mx[i + 1],b[i].sc);
    cur = b[1].sc;
    for (i = 1;i <= n;i++){
        if (i == 1) ans = max(ans,b[i].fs + mx[i + 1]);
        else ans = max(ans,b[i].fs + max(cur,mx[i + 1]));
        cur = min(cur,b[i].sc);
    }
    cout<<ans;
}
