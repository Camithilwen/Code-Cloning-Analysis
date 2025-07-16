//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x*x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

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
const double PI = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
int mapgem[21][21];
VI wque;
vector<char> que;
VI gemx;
VI gemy;
string search(){
	//N y+ S y-
	//E x+ W x-
	int rx = 10;
	int ry = 10;
	int dx = 0;
	int dy = 0;
	int qsize = wque.size();
	mapgem[rx][ry]=0;
	REP(i,qsize){
		dx = 0;
		dy = 0;
		if(que[i] == 'N'){dy++;}
		else if(que[i] == 'S'){dy--;}
		else if(que[i] == 'E'){dx++;}
		else if(que[i] == 'W'){dx--;}
		REP(j,wque[i]){
			rx += dx;
			ry += dy;
			mapgem[rx][ry] = 0;
		}
	}
	REP(i,gemx.size()){
		if(mapgem[gemx[i]][gemy[i]]==1){return "No";}
	}
	return "Yes";
}
int main(){
	int endlchk =8101919;
	int	N;
	int M;
	char d;
	int l;
	int mx,my;
	while(true){
		if(endlchk != 8101919){cout << endl;}
		endlchk = 0;
		cin >> N;
		if(N==0){break;}
		REP(i,20){
			REP(j,20){
				mapgem[i][j]=0;
			}
		}
		REP(i,N){
			cin >> mx >> my;
			mapgem[mx][my] = 1;
			gemx.push_back(mx);
			gemy.push_back(my);
		}
		cin >> M;
		REP(i,M){
			cin >> d >> l;
			que.push_back(d);
			wque.push_back(l);
		}
		
		cout << search();
		que.clear();
		wque.clear();
		gemx.clear();
		gemy.clear();
	}
	return 0;
}