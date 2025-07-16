#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
ll count1(string s){
    ll mini = 0;
    ll cnt = 0;
    ll sz = s.size();
    for (ll i = 0; i < sz;i++){
        if(s[i]==')')
            cnt--;
        else
        {
            cnt++;
        }
        mini = min(mini, cnt);
    }
    return abs(mini);
}
ll count2(string s){
    ll mini = 0;
    ll cnt = 0;
    ll sz = s.size();
    for (ll i = sz - 1; i >= 0; i--)
    {
        if(s[i]=='(')
            cnt--;
        else
        {
            cnt++;
        }
        mini = min(mini, cnt);
    }
    return abs(mini);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i, j, k, l, n, m;
    cin >> n;
    vector<pair<ll, ll>> type1, type2, type3;
    ll bal = 0;
    ll bal1 = 0;
    for (i = 1; i <= n;i++){
        string s;
        cin >> s;
        for(auto x:s){
            if(x=='(')
                bal++;
            else
            {
                bal--;
            }
        }
        ll cnt1 = count1(s);
        bal1 += cnt1;
        ll cnt2 = count2(s);
        bal1 -= cnt2;
        if(cnt1+cnt2==0)
            continue;
        if(cnt2-cnt1>=0){
            type1.pb({cnt1, cnt2});
        }
        else{
            type2.pb({cnt2, cnt1});
        }
    }
    sort(type1.begin(), type1.end());
    sort(type2.begin(), type2.end());
    if (bal!=0||bal1!=0){
        cout << "No\n";
        return 0;
    }
    ll prev = 0;
    ll sz1 = type1.size();
    ll sz2 = type2.size();
    for (i = 0; i < sz1;i++){
        if(type1[i].first>prev){
            cout << "No\n";
            return 0;
        }
        else{
            prev -= type1[i].first;
            prev += type1[i].second;
        }
    }
    for (i = sz2-1; i >=0;i--){
        if(type2[i].second>prev){
            cout << "No\n";
            return 0;
        }
        else{
            prev += type2[i].first;
            prev -= type2[i].second;
        }
    }
    cout << "Yes\n";
    return 0;
}