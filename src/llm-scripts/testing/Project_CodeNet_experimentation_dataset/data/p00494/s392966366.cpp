#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define each(e,c) for(auto&e:c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<" ["<<__LINE__<<"]"<<endl)
struct DUMP:ostringstream{template<class T>DUMP &operator,(const T&t){if(this->tellp())*this<<", ";*this<<t;return *this;}};
#else
#define dump(...)
#endif
template<class T> ostream& operator<<(ostream& os, vector<T> const& v){
    rep(i,v.size()) os << v[i] << (i+1==v.size()?"":" ");
    return os;
}

int main(){
    string s;
    while(cin>>s){
    int n = s.size();
    vi l(n);
    l[0] = 1;
    rep(i,n-1){
        if(s[i+1]==s[i]) l[i+1]=l[i]+1;
        else l[i+1] = 1;
    }
    int ans = 0;
    dump(s);
    dump(l);
    loop(i,1,n-1){
        if(s[i]=='O' && s[i+1]!='O' && i+l[i]<n && i-l[i] >= 0 && l[i+l[i]]>=l[i] && l[i-l[i]]>=l[i] && s[i+l[i]]=='I' && s[i-l[i]]=='J'){
            ans = max(ans,l[i]);
        }
    }
    cout << ans << endl;
}
}