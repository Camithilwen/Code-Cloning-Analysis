#include <cstdio>
#include <algorithm>
using namespace std;

const char *solve(){
	int c[20] = {};
	int a;
	for(int i = 0; i < 5; ++i){
		if(scanf("%d,", &a) == EOF){ return 0; }
		++c[a];
	}
	c[14] = c[1];

	int mc = 0, ms = 0, p = 0;
	for(int i = 1; i < 14; ++i){
		mc = max(mc, c[i]);
		if(c[i] > 1){ ++p; }
		int s = 0;
		for(int j = 0; j < 5 && c[i + j]; ++j){
			++s;
		}
		ms = max(ms, s);
	}
	
	if(mc == 4){ return "four card"; }
	if(p > 1 && mc > 2){ return "full house"; }
	if(ms > 4){ return "straight"; }
	if(mc > 2){ return "three card"; }
	if(p > 1){ return "two pair"; }
	if(p){ return "one pair"; }
	return "null";
}

int main(){
	const char *ans;
	while(ans = solve()){
		puts(ans);
	}
}