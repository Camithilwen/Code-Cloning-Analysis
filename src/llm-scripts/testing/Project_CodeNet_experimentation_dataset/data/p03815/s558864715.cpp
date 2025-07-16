#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

int main() {
    ll x; cin>>x;
    ll n = x/11, r = x%11;
    if(r>6) cout<<n*2 + 2;
    else if(r>0) cout<<n*2 + 1;
    else cout<<n*2;
    return 0;
}