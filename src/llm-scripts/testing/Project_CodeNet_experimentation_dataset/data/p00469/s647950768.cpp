#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)

int n,k;
int card[16];
int check[16];
set<string> ss;

string tos(int a){
	char str[100];
	int i=0;
	while( a>0 ){
		str[i++] = a%10 + '0';
		a /= 10;
	}
	str[i] = 0;
	string s = string(str);
	return string(s.rbegin(), s.rend());
}
void solve(int cnt, string str){
	//printf("%d , %s\n",cnt,str.c_str());
	if( cnt==0 ){
		ss.insert(str);
		return;
	}
	for(int i=0; i<n; i++)if( !check[i] ){
		check[i] = 1;
		solve(cnt-1, str + tos(card[i]));
		check[i] = 0;
	}
	return;
}
int main(){
	while(scanf("%d%d",&n,&k),n|k){
		ss.clear();
		rep(i,n)scanf("%d",&card[i]);
		solve(k,"");
		cout << ss.size() << endl;
	}
	
	return 0;
}