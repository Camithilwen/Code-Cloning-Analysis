#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main()
{
	vi w(10),k(10);
	rep(i,10)
		cin>>w[i];
	rep(i,10)
		cin>>k[i];
	sort(allof(w),greater<int>());
	sort(allof(k),greater<int>());
	cout<<accumulate(allof(w)-7,0)<<" "<<accumulate(allof(k)-7,0)<<endl;
	
	return 0;
}