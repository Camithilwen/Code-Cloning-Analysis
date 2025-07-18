#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

struct murmur_hash {
    const unsigned int random = random_device{}();
    unsigned int operator()(const string& s) const {
        const unsigned int m = 0x5bd1e995;
        const int r = 24;
        unsigned int len = s.size(), h = (random ^ len);
        const unsigned int *z = (const unsigned int*)s.c_str();
        while(len >= 4){
            unsigned int k = *z;
            k *= m, k = (k^(k>>r))*m, h = (h*m)^k;
            z += 1, len -= 4;
        }
        const char *c = (const char *)z;
        switch(len)
        {
        case 3u: h ^= (c[2] << 16);
        case 2u: h ^= (c[1] << 8);
        case 1u: h ^= c[0];
                 h *= m;
        }
        h = (h^(h>>13))*m;
        return (h^(h>>15));
    }
};

unordered_map<string, unordered_map<string, int, murmur_hash>, murmur_hash> mp[2];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    rep(i,(1 << (n-n/2))){
        string red,blue;
        rep(j,n-n/2){
            if((i >> j) & 1){
                red.pb(s[j+n/2]);
            }else{
                blue.pb(s[j+n/2]);
            }
        }
        reverse(all(blue));
        if(len(red) <= len(blue)){
            mp[0][blue][red]++;
        }else{
            mp[1][red][blue]++;
        }
    }
    ll ans = 0;
    rep(i,(1 << n/2)){
        string red, blue;
        rep(j,n/2){
            if((i >> j) & 1){
                red.pb(s[j]);
            }else{
                blue.pb(s[j]);
            }
        }
        reverse(all(blue));
        if(len(red) >= len(blue)){
            ans += mp[0][red][blue];
        }else{
            ans += mp[1][blue][red];
        }
    }
    cout << ans << "\n";
    return 0;
}
