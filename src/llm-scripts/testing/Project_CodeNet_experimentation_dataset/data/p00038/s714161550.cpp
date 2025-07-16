//include
//------------------------------------------
#include <bits/stdc++.h>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

VI n(5, 0);

bool isStraight(){
    int s = 0;
    REP(i, 5) s+=n[i]-n[0]-i;
    if(s == 0) return true;
    else {
        if(n[0] == 1) n[0]+=13;
        SORT(n);

        s = 0;
        REP(i, 5) s+=n[i]-n[0]-i;
        if(s == 0) return true;
        else false;
    }
    return false;
}

int main(){
    while(scanf("%d,%d,%d,%d,%d", &n[0], &n[1], &n[2], &n[3], &n[4])!=EOF){
        int m = 0;
        SORT(n);
        REP(i, 4) FOR(j, i+1, 5) if(n[i]==n[j]) m++;
        switch(m){
            case 1:
                cout << "one pair" << endl;
                break;
            case 2:
                cout << "two pair" << endl;
                break;
            case 3:
                cout << "three card" << endl;
                break;
            case 4:
                cout << "full house" << endl;
                break;
            case 6:
                cout << "four card" << endl;
                break;
            default:
                if(isStraight()) cout << "straight" << endl;
                else cout << "null" << endl;
        }
    }
}