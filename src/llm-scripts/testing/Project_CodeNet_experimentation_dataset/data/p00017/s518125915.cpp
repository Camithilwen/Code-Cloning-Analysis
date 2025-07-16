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

string replace(string s,char table[])
{
	rep(i,s.size())
		if(islower(s[i]))
			s[i]=table[s[i]-'a'];
	return s;
}

int main()
{
	for(string s;getline(cin,s);){
		char table[]="abcdefghijklmnopqrstuvwxyz";
		rep(i,26){
			string s2=" "+s+" ";
			rep(i,s2.size())
				if(s2[i]=='.' || s2[i]=='\n')
					s2[i]=' ';
			s2=replace(s2,table);
			if(s2.find(" the ")!=string::npos || s2.find(" this ")!=string::npos ||s2.find(" that ")!=string::npos){
				cout<<replace(s,table)<<endl;
				break;
			}
			rotate(table,table+1,table+26);
		}
	}
	
	return 0;
}