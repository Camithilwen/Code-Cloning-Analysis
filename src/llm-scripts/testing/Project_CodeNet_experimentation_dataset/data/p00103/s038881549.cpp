#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define rep(a,t) for(int a=0;a<t;a++) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())
#define pb push_back
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	rep(i, n) {
		int base[3];
		int cnt = 0;
		int out = 0;
		rep(i123, 3) { base[i123] = 0; }
		while (true) {
			string thistime;
			cin >> thistime;
			if (thistime == "HIT") {
				cnt += base[2];
				base[2] = base[1];
				base[1] = base[0];
				base[0]=1;
			}
			else if (thistime == "OUT") {
				out++;
				if (out == 3) { break; }
			}
			else {
				cnt += base[2] + base[1] + base[0] + 1;
				base[2] = base[1] = base[0] = 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
