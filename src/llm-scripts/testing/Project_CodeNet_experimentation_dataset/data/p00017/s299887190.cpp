#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int main() {
	string str;
	for(;getline(cin,str);){
		int len=str.size();
		int i,c;
		for(c=1;c<=26;c++){
			for(i=0;i<len;i++){
				if('a'<=str[i]&&str[i]<='z'){
					str[i]++;
					if(str[i]>'z')str[i]='a';
				}
			}
			//cout<<str<<endl;
			if(str.find("the")!=string::npos||str.find("this")!=string::npos||str.find("that")!=string::npos){
				cout<<str<<endl;
				break;
			}
		}
	}
	return 0;
}