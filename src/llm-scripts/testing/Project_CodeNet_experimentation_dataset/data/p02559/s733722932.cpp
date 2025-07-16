#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace atcoder;

int main(){
    int n,q;
    std::cin >> n >> q;
    fenwick_tree<ll> fw(n);
    REP(i,n){
        int input;
        std::cin >> input;
        fw.add(i,input);
    }
    REP(i,q){
        int f,p,x;
        std::cin >> f >> p >> x;
        if(f==0){
            fw.add(p,x);
        }
        else{
            std::cout << fw.sum(p,x) << std::endl;
        }
    }
}