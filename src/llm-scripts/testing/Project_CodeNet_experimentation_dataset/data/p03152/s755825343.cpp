#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

map<int, int> mp;
vector<LL> A, B, arr;

bool ok[1000*1000+1];
int main() {
    int N = readInt();
    int M = readInt();
    
    REP(i, N) {
        int a = readInt();
        A.push_back(a);
        mp[a]++;
    }
    
    for(auto e: mp){
        if(e.second>=2){
            cout << 0 << endl;
            return 0;
        }
    }
    
    REP(i, M){
        int b = readInt();
        B.push_back(b);
        mp[b]++;
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            arr.PB(min(A[i], B[j]));
        }
    }
    
    //for(int i=0; i<N*M; ++i) cout << arr[i] << endl;
    
    sort(arr.begin(), arr.end());
    for(auto e: mp){
        if(e.second>=3){
            cout << 0 << endl;
            return 0;
        }else if(e.second==2){
            ok[e.first] = true;
        }
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    //for(int i=0; i<N*M; ++i) cout << arr[i] << endl;
    LL ans=1;
    for(int i=N*M; i>=2; --i){
        
        if(ok[i]){
            continue;
        }
        if((A.end() - lower_bound(A.begin(), A.end(), i)) * (B.end() - lower_bound(B.begin(), B.end(), i)) - (N*M-i) <= 0) {
            cout << 0 << endl;
            return 0;
        }
        if(find(A.begin(), A.end(), i)!=A.end()){
           ans *= B.end() - lower_bound(B.begin(), B.end(), i);
        }else if(find(B.begin(), B.end(), i)!=B.end()){
            ans *= A.end() - lower_bound(A.begin(), A.end(), i);
        }else{
        
        ans *= (A.end() - lower_bound(A.begin(), A.end(), i)) * (B.end() - lower_bound(B.begin(), B.end(), i)) - (N*M-i);
        
        }ans %= MOD;
    }
    cout << ans << endl;
    
    
	return 0;
}