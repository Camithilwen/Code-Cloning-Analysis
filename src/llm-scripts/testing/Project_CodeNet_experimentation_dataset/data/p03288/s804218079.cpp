#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	if(t < 1200)
		cout << "ABC";
	else if(t < 2800)
		cout << "ARC";
	else
		cout << "AGC";
	return 0;
}