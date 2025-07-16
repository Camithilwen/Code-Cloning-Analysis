#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

#define sz			size()
#define lgt			length()
#define rep(i,n)	for (int i = 0; i < n; i++)
#define ALL(X)		(X).begin(),(X).end()
#define RALL(X)		(X).rbegin(),(X).rend()
#define pb			push_back
#define SORT(a)		sort(ALL(a));
#define RSORT(a)	sort(RALL(a));
#define mp			make_pair
#define dump(x)		cerr<<#x<<" = "<<(x)<<endl;
#define fir			first
#define sec			second

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<string> vs;

int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
vs form(string a,char s){vs v;string b;rep(i,a.lgt){if(a[i]==s){v.pb(b);b="";}else b+=a[i];}v.pb(b);return v;}
vi formint(string a,char s){vi v;string b;rep(i,a.lgt){if(a[i]==s){v.pb(toInt(b));b="";}else b+=a[i];}v.pb(toInt(b));return v;}

const double EPS=1e-10,PI=acos(-1.0);
const int INF=2100000000;

int main(void)
{
	int n, k;
	while (cin >> n >> k, n && k){
		string num[16];
		vector <string> ans;
		for (int i = 0; i < n; i++)	cin >> num[i];
		
		if (k == 2){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (i != j){
//						cout << i << " " << j << endl;
						string tmp;
						tmp += num[i];
						tmp += num[j];
//						cout << "*" << tmp << endl;
						ans.pb(tmp);
					}
				}
			}
		}
		if (k == 3){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					for (int k = 0; k < n; k++){
						if (i != j && j != k && i != k){
							string tmp;
							tmp += num[i];
							tmp += num[j];
							tmp += num[k];
							ans.pb(tmp);
						}
					}
				}
			}
		}
		if (k == 4){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					for (int k = 0; k < n; k++){
						for (int l = 0; l < n; l++){
							if (i != j && i != k && i != l && j != k && j != l && k != l){
								string tmp;
								tmp += num[i];
								tmp += num[j];
								tmp += num[k];
								tmp += num[l];
								ans.pb(tmp);
							}
						}
					}
				}
			}
		}
		
		ans.pb("2100000000");
		SORT(ans);
		int res = 0;
		for (int i = 0; i < ans.sz - 1; i++){
			if (ans[i] != ans[i + 1]) res++;
		}
		cout << res << endl;
	}
	
	return 0;
}