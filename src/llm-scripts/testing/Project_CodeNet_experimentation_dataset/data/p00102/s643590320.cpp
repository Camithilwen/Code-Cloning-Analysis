#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;



int main(void){

string ws;
int n;
	while(cin >> n){
		if(n==0 || cin.eof()) break;
		vector<vector<int> > hg(n+1,vector<int>(n+1,0));
		rep(i,n) rep(j,n) cin >> hg[i][j];
		rep(i,n) rep(j,n){
			hg[n][i] += hg[j][i];
			hg[i][n] += hg[i][j];
		}
		rep(i,n) hg[n][n] += hg[i][n];
		rep(i,n+1){
			rep(j,n+1) printf("%5d",hg[i][j]);
			printf("\n");
		}
	}
	return 0;
	
}