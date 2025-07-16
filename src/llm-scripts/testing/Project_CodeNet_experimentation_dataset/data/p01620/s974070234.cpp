#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

vector<char> cmap;
char getrev(char c,int kagi){
	int rst;
	if(c>='a') rst = c -'a' ;
	else rst = c - 'A'+ ('Z'-'A'+1);
	if(rst-kagi<0) return cmap[rst-kagi+cmap.size()];
	else return cmap[rst-kagi];
}
int main(){
	for(int i='a';i<'z'+1;i++) cmap.pb(i);
	for(int i='A';i<'Z'+1;i++) cmap.pb(i);

	while(1){
		int n;
		cin >> n;
		if(n==0) break;
		int klist[100];
		REP(i,n){
			cin >> klist[i];
		}
		string ango;
		cin >> ango;
		int nowkagi = 0;
		REP(i,ango.size()){
			cout << getrev(ango[i],klist[nowkagi]);
			if(nowkagi==n-1) nowkagi = 0;
			else nowkagi++;
		}
		cout << endl;
	}
}