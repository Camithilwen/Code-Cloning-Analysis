
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <complex>
#include <stack>
#include <climits>
#include <set>
#include <numeric>

using namespace std;

int t[5];

bool straight()
{
	if(t[0] == 1 && t[1] == 10 && t[2] == 11 && t[3] == 12 && t[4] == 13) return true;
	for (int i = 0; i < 4; i++){
		if(t[i+1]-t[i] != 1) return false;
	}
	return true;
}

int main()
{
	while(~scanf("%d,%d,%d,%d,%d",t,t+1,t+2,t+3,t+4)){
		sort(t,t+5);
		if(t[0] == t[3] || t[1] == t[4])
			puts("four card");
		else if( (t[0] == t[1] && t[2] == t[4]) || (t[0] == t[2] && t[3] == t[4]))
			puts("full house");
		else if(straight())
			puts("straight");
		else if(t[0] == t[2] || t[1] == t[3] || t[2] == t[4])
			puts("three card");
		else if( (t[0] == t[1] && (t[2] == t[3] || t[3] == t[4])) || (t[1] == t[2] && t[3] == t[4]) )
			puts("two pair");
		else if( t[0] == t[1] || t[1] == t[2] || t[2] == t[3] || t[3] == t[4])
			puts("one pair");
		else 
			puts("null");
	}
	return 0;
}