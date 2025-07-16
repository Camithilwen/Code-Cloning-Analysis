#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define COUNT(i, n) for(int i = 1; i <= n; i ++)
#define ITER(c) __typeof((c).begin())
#define each(c, it) for(ITER(c) it =(c).begin(); it!=(c).end(); it++)
#define ALL(c) c.begin(), c.end()
#define mp make_pair
#define pb push_back
#define MEMSET(v, h) memset((v), h, sizeof(v))
 
using namespace std; 

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;
 
int main(void){
    for(int n, m, s; s = 0, cin >> n >> m, n; cout << s << endl){
        priority_queue<int> p;
        rep(i, n){
            int in; cin >> in;
            p.push(in);
        }
        COUNT(i, n){
            if(i % m) s += p.top();
            p.pop();
        }
    }
 
    return 0;
}