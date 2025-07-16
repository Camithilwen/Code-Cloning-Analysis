//2020年4月17日現在

#include<stdio.h>
#include<cmath>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<queue>
#include<set>
#include<utility>
#include<iomanip>
#include<limits>
#include<thread>
#include<map>
#include<stack>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<tuple>
#include <cstdio>
#include <iterator>

using namespace std;

template <class... A>
void prints() { cout << "\n"; }
template <class... A>
void prints_rest() { cout << "\n"; }
template <class T, class... A>
void prints_rest(const T &first, const A &... rest) { cout << " " << first; prints_rest(rest...); }
template <class T, class... A>
void prints(const T &first, const A &... rest) { cout << first; prints_rest(rest...); }

namespace {
    // printElems(&a[0], &a[n]);　みたいな感じで使う。
    void printElems(const int* begin, const int* end)
    {
        for (const int* p = begin; p != end; ++p) {
            std::cout << *p << ' ';
        }
        std::cout << std::endl;
    }
}

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n+1; i++)
#define repr(i,n) for(int i=n-1; i>=0; i--)
#define repr1(i,n) for(int i=n; i>0; i--)
#define FOR(i,j,n) for(int i=j; i < n; i++)
#define souatari(i,j,n) rep1(i,n-1)rep(j,i)
#define souatari1(i,j,n) for(int i=2; i<n+1; i++)rep1(j,i-1)
#define mp make_pair
#define F first
#define S second
#define elif else if

typedef long long ll;
typedef vector<int>  vi;
typedef vector<vi>  vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef array<int,3> arr3;
typedef long double D;


const ll llinf =  numeric_limits<ll>::max();
const ll _llinf = numeric_limits<ll>::lowest();
const int inf = numeric_limits<int>::max();
const int _inf = numeric_limits<int>::lowest();
const double dinf = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const ll BIG = 10000000000000000;


ll a[200005];
bool af[200005];

int main(){
    ll n;
    cin >> n;
    rep(i,n) cin >> a[i];
    map<ll,ll,greater<ll>> m;
    rep(i,n){
        if(m.find(a[i]) != m.end()){
            m[a[i]]++;
        }
        else{
            m.insert(mp(a[i],1));
        }
    }
    int cnt = 0;

    //if(if(m.find(3) != m.end() && m.at(3)>0))


    for(auto i=m.begin(); i!= m.end(); ++i){
        ll tmp = 1;
        ll key = i->first;
        ll val = i->second;

        while(tmp<key) tmp*=2;
        //prints(key,val,tmp);


        if(tmp == key){
            cnt+=val/2;
            m[key] -= val/2;
            continue;
        }
        else{
            if(m.find(tmp-key) != m.end() && m.at(tmp-key)>0){
                cnt+=min(val,m[tmp-key]);
                m[tmp-key]-=min(val,m[tmp-key]);
            }
        }
    }
    prints(cnt);



	return 0;
}

