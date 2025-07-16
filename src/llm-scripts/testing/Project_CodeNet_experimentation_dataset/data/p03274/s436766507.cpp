#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fill(x,v) memset(x,v,sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x <<": " << x << endl
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;


const int MAX = 3002;
const ll INF = 1LL<<62;

bool exist[30];
vi mayor, menor;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll on  = 0, a;
    rep(i,0,n){
        cin >> a;
        if(a < 0) menor.pb(a);
        if(a > 0) mayor.pb(a);
        if(a == 0) on = 1; 
    }

    ll sobra = k - on;
    ll rpta = 0;
    if(sobra){
        reverse(all(menor));
        ll aux = INF;
        int j;
        ll aux1, aux2;
        for(int i = 0; i <= min(sobra, ll(mayor.size())); i++){
            j = sobra - i;
            if(j > menor.size()) continue;
            aux1 = 0;
            aux2 = 0;
            if(i) aux1 = mayor[i-1];
            if(j) aux2 = menor[j-1]*-1;
            
            if(aux1 > aux2) swap(aux1, aux2);
            aux = min(aux, aux1+aux1+aux2);
        }
        rpta  += aux;
    }
    cout << rpta << endl;

}

int main(){
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}