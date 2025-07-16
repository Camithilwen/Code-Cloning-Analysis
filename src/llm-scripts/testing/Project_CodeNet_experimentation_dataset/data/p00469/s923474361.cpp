#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
const int INF = 10000000;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
 
int n, k;
set<string> st;
string s;
vi v;
 
void calc(int c, vi u){
    if(u.size() == k){
    	// rep(i, u.size()){
    	// 	cout<<" "<<u[i];
    	// }
    	// cout<<endl;
    	sort(all(u));
        do{
            string t;
            for(int i = 0; i < k; i++){
                t += to_string(u[i]);
            }
            st.insert(t);
        }while(next_permutation(all(u)));
        return;
    }
    for(int i = c; i<n; i++){
        u.pb(v[i]);
        calc(i+1, u);
        u.pop_back();
    }
}
 
 
int main(){
    while(cin>>n>>k){
        if(n == 0 && k == 0) break;
        v = vi(n);
        rep(i, n) cin>>v[i];
        s = "";
        st.clear();
        vi tmp;
        calc(0,tmp);
        // for(auto it = st.begin(); it != st.end(); it++){
        // 	cout<<"  "<<*it<<endl;
        // }
        cout<<st.size()<<endl;
    }
}