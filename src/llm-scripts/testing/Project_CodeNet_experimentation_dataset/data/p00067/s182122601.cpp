#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
#define  MAX 100
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int field[12][12];
char s[12];

void dfs(int x,int y){
	field[y][x] = 0;

	for(int i = 0;i < 4;i++){

		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || ny < 0 || nx >= 12 || ny >= 12){

			continue;

		}else if(field[ny][nx] == 1){
			dfs(nx,ny);
		} 
	}
	
	
}

void setfield(char S[],int y){
	rep(i,12){
		if(S[i] == '1'){
			field[y][i] = 1;
		}else{
			field[y][i] = 0;
		}
	}
}

int countisland(){
	int count = 0;
	rep(y,12){
		rep(x,12){
			if(field[y][x] == 1){
				count++;
				dfs(x,y);
			}
		}
	}
	return count;
}

int main(){

	while(true){
		if(scanf("%s",s) == EOF) break;
		setfield(s,0);
		FOR(i,1,12){
			scanf("%s",s);
			setfield(s,i);
		}
		cout << countisland() << endl;
	}

	return 0;
}