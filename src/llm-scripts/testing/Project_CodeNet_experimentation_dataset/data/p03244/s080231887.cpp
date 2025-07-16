#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int n, a[100005];
vector<pair<int,int>> vec, vec2;
unordered_map<int,int> mp, mp2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i+= 2)mp[a[i]]++;
    for(int i = 2; i <= n; i += 2)mp2[a[i]]++;
    for(auto i : mp)vec.pb({i.s, i.f});
    for(auto i : mp2)vec2.pb({i.s, i.f});
    sort(vec.begin(), vec.end()); sort(vec2.begin(), vec2.end());
    int cnt = 1e9;
    int delta = n/2;
    if(vec.size() == 1 && vec2.size() == 1){
        if(vec[0].s == vec2[0].s){
            cnt = delta;
        }
        else{
            cnt = 0;
        }
    }
    else{
        if(vec[vec.size()-1].s != vec2[vec2.size()-1].s){
            cnt = delta - vec[vec.size()-1].f + delta - vec2[vec2.size()-1].f;
        }
        else{
            if(vec.size() > 1)cnt = min(cnt, delta - vec2[vec2.size()-1].f + delta - vec[vec.size()-2].f);
            else cnt = min(cnt, delta + delta - vec2[vec2.size()-1].f);
            if(vec2.size() > 1)cnt = min(cnt, delta - vec2[vec2.size()-2].f + delta - vec[vec.size()-1].f);
            else cnt = min(cnt, delta + delta - vec[vec.size()-1].f);
        }
    }
    cout << cnt << endl;
    return 0;
}
