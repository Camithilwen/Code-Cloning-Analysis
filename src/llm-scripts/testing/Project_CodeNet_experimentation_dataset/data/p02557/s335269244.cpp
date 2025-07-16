#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair
#define size(a) int(a.size())

const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1);

ll modexp(ll x,ll n,int md){
    if(n==0)return 1;
    if(n%2==0)return modexp((x*x)%md,n/2,md);
    return (x*modexp((x*x)%md,n/2,md))%md;
}

set<int> g[200001];
int main(){
    fastio;
    //clock_t tm = clock();
    int n;
    cin>>n;
    vi a(n),b(n),na(n+1,0),nb(n+1,0);
    priority_queue<pii>g1;
    f(i,0,n){
        cin>>a[i];na[a[i]]++;
        g[a[i]].insert(i);
    }
    f(i,0,n){
        cin>>b[i];nb[b[i]]++;
    }
    priority_queue<pii>g2;
    f(i,1,n+1){
        if(na[i]+nb[i]>n){
            cout<<"No"<<endl;
            return 0;
        }
        if(nb[i]>0){
            g2.push({nb[i],-i});
        }
        if(na[i]>0){
            g1.push({na[i],i});
        }
    }
    reverse(all(b));
    vi ans(n,0);
    while(!g2.empty()){
        auto pr=g2.top();
        g2.pop();
        if(pr.first>1){
            --pr.first;
            g2.push(pr);
        }
        pr.second*=-1;
        auto qr=g1.top();
        g1.pop();
        if(qr.second!=pr.second) {
            if (qr.first > 1) {
                --qr.first;
                g1.push(qr);
            }
            ans[*g[qr.second].begin()]=pr.second;
            g[qr.second].erase(*g[qr.second].begin());
        }
        else{
            if(g1.empty())break;
            auto qr1=g1.top();
            g1.pop();g1.push(qr);qr=qr1;
            if (qr.first > 1) {
                --qr.first;
                g1.push(qr);
            }
            ans[*g[qr.second].begin()]=pr.second;
            g[qr.second].erase(*g[qr.second].begin());
        }
    }
    cout<<"Yes"<<endl;
    fr(i,ans)cout<<i<<" ";
    cout<<endl;
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}