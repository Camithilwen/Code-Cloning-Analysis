#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Rep(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define Repr(i, b, e) for(int (i) = (b) - 1; (i) >= (e); --(i))
#define Print(x) cout << (x) << endl 
#define Min2(a, b) ((a) < (b)) ? (a) : (b)
#define Max2(a, b) ((a) > (b)) ? (a) : (b)

typedef long long ll;

using namespace std;

int N, K;
string C[10];
set<string> bt;

void dfs(string str, int k, int state){
    if(k == 0){
        bt.insert(str);
        return;
    }
    Rep(i, 0, N){
        if((1 << i) & state) continue;
        dfs(str + C[i], k - 1, state | (1 << i));
    }
}

int main(){
    while(true){
        cin >> N >> K;
        if(N == 0 && K == 0) break;
        Rep(i, 0, N) cin >> C[i];
        dfs("", K, 0);
        Print(bt.size());
        bt.clear();
    }
    return 0;
}
