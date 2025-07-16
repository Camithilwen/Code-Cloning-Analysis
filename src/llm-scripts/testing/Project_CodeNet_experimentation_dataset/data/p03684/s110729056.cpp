#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
pii p[100005];
int x[100005], y[100005];
int r[100005];
int root(int a){
    return r[a] == a?a:(r[a]=root(r[a]));
}
void merge(int a, int b){
    a = root(a), b = root(b);
    if(a != b) r[a] = b;
}
int main(){
    int n;
    scanf("%d", &n);   
    for(int i=1;i<=n;i++){
        scanf("%d%d", &x[i], &y[i]);
        p[i] = pii(x[i], i);
        r[i] = i;
    }
    sort(p+1, p+1+n);
    vector<pipii> edges;
    for(int i=2;i<=n;i++) edges.eb(pipii(p[i].fi-p[i-1].fi, pii(p[i].se, p[i-1].se)));
    sort(all(edges));
    for(int i=1;i<=n;i++) p[i] = pii(y[i], i);
    sort(p+1, p+1+n);
    for(int i=2;i<=n;i++) edges.eb(pipii(p[i].fi-p[i-1].fi, pii(p[i].se, p[i-1].se)));
    sort(all(edges));
    int ans = 0;
    for(int i=0;i<sz(edges);i++){
        if(root(edges[i].se.fi) != root(edges[i].se.se)){
            merge(edges[i].se.fi, edges[i].se.se);
            ans += edges[i].fi;
        }
    }
    printf("%d\n", ans);
}