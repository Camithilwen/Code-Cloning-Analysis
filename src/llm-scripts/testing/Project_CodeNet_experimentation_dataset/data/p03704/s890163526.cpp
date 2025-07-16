#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 25;

int d;
LL p[N];
int sub1[N], sub2[N];      // sub1 not front, sub2 is front

vector <LL> v;

void dfs(int s, int e, vector <pair <LL, LL> > &w, LL val, LL cnt){
    if (s == e){
        w.push_back(make_pair(val, cnt));
        return ;
    }

    for (int i = -9; i < 10; i++)                     // 枚举差值
        dfs(s + 1, e, w, val + i * v[s], cnt * (s ? sub1[i + 10] : sub2[i + 10]));
}

LL solve(int len){
    v.clear();
    for (int i = 0; i < len - 1 - i; i++) v.push_back(p[len - 1 - i] - p[i]);

    vector <pair <LL, LL> > v1, v2;
    dfs(0, (v.size() + 1) >> 1, v1, 0, 1);
    dfs((v.size() + 1) >> 1, v.size(), v2, 0, 1);

    LL ans = 0;
    map <LL, LL> mp;
    for (int i = 0; i < v2.size(); i++) mp[v2[i].first] += v2[i].second;
    for (int i = 0; i < v1.size(); i++) ans += mp[d - v1[i].first] * v1[i].second;

    if (len & 1) ans *= 10;
    return ans;
}

int main(){
    p[0] = 1;
    for (int i = 1; i < 20; i++) p[i] = p[i - 1] * 10;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) sub1[i - j + 10]++;
    for (int i = 0; i < 10; i++)
        for (int j = 1; j < 10; j++) sub2[i - j + 10]++;

    scanf("%d", &d);
    LL ans = 0;
    for (int i = 2; i <= 18; i++) ans += solve(i);

    printf("%lld", ans);

    return 0;
}