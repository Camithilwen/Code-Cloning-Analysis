#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

vector<pl> toppo (pl *p, int si) {
    sort(p, p+si);
    vector<pl> ret;
    ret.push_back(p[0]);
    for (int i = 1; i < si; i++) {
        while (ret.size() > 1) {
            int tmp = ret.size()-1;
            if ((p[i].second-ret[tmp-1].second)*(ret[tmp].first-ret[tmp-1].first) >= 
                (ret[tmp].second-ret[tmp-1].second)*(p[i].first-ret[tmp-1].first)) {
                ret.pop_back();
            } else {
                break;
            }
        }
        ret.push_back(p[i]);
    }
    vector<pl> ret2;
    ret2.push_back(p[si-1]);
    for (int i = si-2; i >= 0; i--) {
        while (ret2.size() > 1) {
            int tmp = ret2.size()-1;
            if ((p[i].second-ret2[tmp-1].second)*(ret2[tmp].first-ret2[tmp-1].first) >= 
                (ret2[tmp].second-ret2[tmp-1].second)*(p[i].first-ret2[tmp-1].first)) {
                ret2.pop_back();
            } else {
                break;
            }
        }
        ret2.push_back(p[i]);
    }
    ret2.pop_back();
    for (int i = 1; i < ret2.size(); i++) ret.push_back(ret2[i]);
    return ret;
}

int n;
pl pos[100], tmp[100];
double ans[100];

int main() {
    cin >> n;
    rep(i,n) cin >> pos[i].first >> pos[i].second;
    rep(i,n) tmp[i] = pos[i];
    vector<pl> topp = toppo(tmp, n);
    int si = topp.size();
    for (int i = 0; i < si; i++) {
        pl pre = topp[(i-1+si)%si];
        pl now = topp[i];
        pl nxt = topp[(i+1)%si];
        double dy1 = now.second-pre.second, dx1 = now.first-pre.first;
        double dy2 = nxt.second-now.second, dx2 = nxt.first-now.first;
        double d1 = atan2(dy1, dx1);
        double d2 = atan2(dy2, dx2);
        double d = abs(d1-d2);
        if (d > PI) d = 2*PI-d;
        rep(j,n) {
            if (topp[i] == pos[j]) {
                ans[j] = d/(2*PI);
            }
        }
    }
    rep(i,n) {
        printf("%.9f\n", ans[i]);
    }
}