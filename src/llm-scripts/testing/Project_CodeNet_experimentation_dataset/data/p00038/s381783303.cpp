#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(c,i) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main()
{
	for(int a[5];cin>>a[0];){
		repi(i,1,5)
			scanf(",%d",a+i);
		sort(a,a+5);
		
		int hist[13]={0};
		rep(i,5)
			hist[a[i]-1]++;
		sort(hist,hist+13,greater<int>());
		
		string res;
		if(hist[0]==4)
			res="four card";
		else if(hist[0]==3 && hist[1]==2)
			res="full house";
		else if(a[0]+1==a[1] && a[1]+1==a[2] && a[2]+1==a[3]&& a[3]+1==a[4] ||
				a[0]==1 && a[1]==10 && a[2]==11 && a[3]==12 && a[4]==13)
			res="straight";
		else if(hist[0]==3)
			res="three card";
		else if(hist[0]==2 && hist[1]==2)
			res="two pair";
		else if(hist[0]==2)
			res="one pair";
		else
			res="null";
		
		cout<<res<<endl;
	}
	
	return 0;
}