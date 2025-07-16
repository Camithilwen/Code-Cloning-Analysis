#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}
int lcm(int a,int b){
    return b / gcd(a,b) * a;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int x,y; cin >> x >> y;
    if(y >= x && y >0 && x < 0 && abs(y)> abs(x)) cout << 1 + y + x << endl;
    else if(y >= x && y >0 && x < 0) cout << -y - x + 1 << endl;
    else if(y >= x) cout << y - x << endl;
    else if(y > 0) cout << 1 - y + x + 1 << endl;
    else if(y == 0) cout << 1 + x << endl;
    else if(x >= 0 && abs(x) >= abs(y)) cout << 1 + abs(x) - abs(y) << endl;
    else if(x >= 0) cout << abs(y) - abs(x) + 1 << endl;
    else if(x > y)cout << 1 + abs(y) - abs(x) + 1 << endl;
}