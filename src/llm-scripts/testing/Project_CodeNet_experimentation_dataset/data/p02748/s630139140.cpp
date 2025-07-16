#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
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
#include <cmath>
#include <numeric>
#include <float.h>
#include <math.h>
#include <sstream>
#include <iterator>
using namespace std;
using Graph = vector<vector<int>>;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()
// 大きい順
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vl vector<ll>
const  long long INF = 1LL << 60;
typedef  long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}



int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n % 2 == 0 || n % 3 == 0) return false;
    // n は 2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }

    return true;
}

map<int,int> mp;

int primeFactorization(int a){ //素因数分解を出力するプログラム
    int i,sq;
    if(a%2==0){ //偶数の場合
        if(!mp.count(2)){
            mp[2] = 1;
        }
        else{
            mp[2] +=1;
        }
        return primeFactorization(a/2); //2で割った値で再帰
    }
    sq = sqrt(a);
    for(i=3;i<=sq;i+=2){ //3以上√a以下の奇数の場合
        if(a%i==0){
            if(!mp.count(i)){
                mp[i] = 1;
            }
            else{
                mp[i] += 1;
            }
            return primeFactorization(a/i); //割れた値で再帰
        }
    }
    //偶数でも3以上√a以下の奇数の場合でも割り切れない場合
    if(a!=1){ //aが1でないなら、a自身は素数
        if(!mp.count(a))
        mp[a] = 1;
        else{
            mp[a] += 1;
        }
    }
    return 0;
}


ll kaizyou(ll n){
    if(n == 1){
        return 1;
    }
    else{
        return (n * kaizyou(n-1)) % 1000000007;
    }
}






int main(){
int A,B,M; cin >> A >> B >> M;
vi a(A);
vi b(B);
int p,q;
p = q = 100000000;
rep(i,A){
 cin >> a[i];
 chmin(p,a[i]);
}
rep(i,B) {
    cin >> b[i];
    chmin(q,b[i]);
}
int mi = p + q;
rep(i,M){
    int x,y,c;cin >> x >> y >> c;
    x--;
    y--;
    chmin(mi,a[x]+b[y]-c);
}
cout << mi << endl;
}
