//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <stdio.h>
//end of libraries ;
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// ll lmax(ll o , ll w) {if(o>w)return o; return w;}
// ll lmin(ll o , ll w) {if(o<w)return o; return w;}
#define LNF 3999999999999999999
#define INF 999999999
#define N 3000003
#define PI 3.14159265359
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define ll long long
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define mkp(a,b) make_pair(a,b)
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
ll n;
string ans;
int main(){
fcin;
    cin >> n;
    ll p = 1;
    while(n){
        n-=p;
        char x = ('a' + (n/p)%26);
        ans = x + ans;
        p*=26;
        if(p>n) break;
    }
    cout << ans << '\n';

}
