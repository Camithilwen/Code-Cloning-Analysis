#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main() {
    cout<<fixed<<setprecision(10);

    ll n; cin>>n;
    string s; cin>>s;
    ll q; cin>>q;

    vint ruiM(n+1, 0);
    rep(i,n) ruiM[i+1] = ruiM[i] + (ll)(s[i] == 'M');



    while(q-->0){
        ll k; cin>>k;
        ll left = -k;
        ll right = 0;
        vint cnt(2,0);
        ll ans = 0;

        while(right < n){
            if(left >= 0){
                if(s[left] == 'D'){
                    cnt[0]--;
                    cnt[1] -= ruiM[right] - ruiM[left+1];
                }
            }
            if(s[right] == 'D'){
                cnt[0]++;
            }else if(s[right] == 'M'){
                cnt[1] += cnt[0];
            }else if(s[right] == 'C'){
                ans += cnt[1];
            }
            left++;
            right++;
        }
        cout<<ans<<endl;
    }

    return 0;

}