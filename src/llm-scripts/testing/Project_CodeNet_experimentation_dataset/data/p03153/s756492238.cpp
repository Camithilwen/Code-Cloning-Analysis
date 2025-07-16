#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <complex>
#include <cassert>
#include <cstring>
#include <functional>
#include <bitset>
#include <climits>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define cmn(x,y) x=min(x,y)
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

template<typename T> class segtree {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree(vector<T>& v) : sz((int)v.size()){
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n, make_pair(numeric_limits<T>::max(), sz));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = min(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
    	node[k+n] = make_pair(a, k);
        k += n;
    	while(k>>=1){
            node[k] = min(node[2*k], node[2*k+1]);
    	}
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::max(), sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::max(), sz);
        a += n, b += n;
        while(a != b){
            if(a % 2) cmn(res1, node[a++]);
            if(b % 2) cmn(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return min(res1, res2);
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            pair<T, int> p;
            p = query(i,i+1);
            cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
        }
    }
};


int n;
ll d;
ll saiki(segtree<ll>& sg, int a,int b){
    //cerr << a << " " << b << endl;
    if(b==a+1)return 0;
    auto p = sg.query(a,b);
    ll s = p.first;
    ll ans = 0;
    int ind = p.second;
    if(ind-1>=a){
        ll xx = sg.query(ind-1,ind).first;
        ans += s+d+xx;
        sg.update(ind-1,min(xx,s+d));
        ans += saiki(sg,a,ind);
    }
    if(ind+1<b){
        ll xx = sg.query(ind+1,ind+2).first;
        ans += s+d+xx;
        sg.update(ind+1,min(xx,s+d));
        ans += saiki(sg,ind+1,b);
    }
    return ans;
}


int main(){
    cin >> n >> d;
    vector<ll>v(n+1);
    rep(i,n)cin >> v[i];
    segtree<ll> sg(v);
    ll ans = saiki(sg,0,n);
    cout << ans << endl;
    return 0;
}
