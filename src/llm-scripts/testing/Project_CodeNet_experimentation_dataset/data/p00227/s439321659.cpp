#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(ull i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define iter(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define riter(i,c) for(auto i=(c).rbegin(); i!=(c).rend(); ++i)
const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;
namespace std {
    template<typename T>ostream&operator<<(ostream&os, vector<T>const&v){
        iter(it,v) os<<*it<<(it+1==v.end()?"":",");
        return os;
    }
    template<typename T, typename U>ostream&operator<<(ostream&os,const pair<T,U>&p){
        return os << "[" << p.dirst << "," << p.second << "]";
    }
}

#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
int main(){
    int m, n;
    while(cin>>n>>m && m|n){
        vi p(n);
        int free = 0;
        int sum = 0;
        rep(i,n){
            cin >> p[i];
            sum += p[i];
        }
        sort(all(p));
        // テ」ツ??」ツ?暗」ツ?凝」ツつ?
        for(int i=n-m;i>=0;i-=m)free+=p[i];
        cout << sum - free << endl;
    }
}