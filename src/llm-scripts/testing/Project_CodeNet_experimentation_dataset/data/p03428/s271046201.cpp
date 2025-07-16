#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

//点a,bの距離の2乗
ld dist2(pdd a, pdd b){
    ld x = b.first - a.first;
    ld y = b.second - a.second;
    return x*x + y*y;
}

//点a,bの距離
ld dist(pdd a, pdd b){
    return sqrt(dist2(a, b));
}

//内積a・b
ld dot(pdd a, pdd b){
    ld x = a.first * b.first;
    ld y = a.second * b.second;
    return x+y;
}

//a,bを横に並べた行列の行列式
ld det(pdd a, pdd b){
    ld x = a.first * b.second;
    ld y = a.second * b.first;
    return x-y;
}

//b-a
pdd dif(pdd a, pdd b){
    pdd p;
    p.first = b.first - a.first;
    p.second = b.second - a.second;
    return p;
}

//点a,bの中点
pdd mid(pdd a, pdd b){
    pdd p;
    p.first = (a.first + b.first)/2;
    p.second = (a.second + b.second)/2;
    return p;
}

int main(){
    int N;
    cin >> N;
    pdd p[N];
    map<pdd, int> mp;
    rep(i, N){
        cin >> p[i].first >> p[i].second;
        mp[p[i]] = i;
    }
    sort(p, p+N);
    pdd q[N+1];
    int k = 1;
    q[0] = p[0];
    rep2(i, 1, N-1){
        if(i < N-1 && p[i-1].first == p[i].first) continue;
        while(k > 1 && det(dif(q[k-1], p[i]), dif(q[k-1], q[k-2])) <= 0) k--;
        q[k] = p[i], k++;
    }
    int t = k;
    rep3(i, N-2, 0){
        if(i > 0 && p[i+1].first == p[i].first) continue;
        while(k > t && det(dif(q[k-1], p[i]), dif(q[k-1], q[k-2])) <= 0) k--;
        q[k] = p[i], k++;
    }
    k--;
    ld ans[N];
    fill_n(ans, N, 0);
    ld pi = 3.141592653589793238;
    rep(i, k){
        int j = (k+i-1)%k, l = (i+1)%k;
        pdd x[2];
        x[0] = mid(q[i], q[j]);
        x[1] = mid(q[i], q[l]);
        ld r[3], R[3];
        rep(a, 2){
            r[a] = dist(q[i], x[a]);
            R[a] = dist2(q[i], x[a]);
        }
        r[2] = dist(x[0], x[1]);
        R[2] = dist2(x[0], x[1]);
        ld cos = -(R[0]+R[1]-R[2])/(2*r[0]*r[1]);
        if(cos > 1) cos = 1;
        elif(cos < -1) cos = -1;
        ld the = acos(cos);
        int n = mp[q[i]];
        ans[n] = the/(2*pi);
    }
    rep(i, N) cout << setprecision(15) << ans[i] << endl;
}