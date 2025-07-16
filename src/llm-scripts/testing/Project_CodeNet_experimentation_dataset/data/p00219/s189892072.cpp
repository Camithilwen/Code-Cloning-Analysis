#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <list>
#include <map>

#define rep(i,p,n) for(int i=(int)p;i<(int)n;i++)
#define repp(i,p,n) for(int i=(int)p;i>=(int)n;i--)
#define Sort(x) sort(x.begin(),x.end());
#define ll long long 
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi <vector<vector<vector<int>>> 
#define vc vector<char> 
#define vvc vector<vector<char>>
#define vvvc vector<vector<vector<char>>> 
#define INF 2000000000

using namespace std;

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;

		vector<int> v(10,0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x; 
			v[x]++;
		}

		for (int i = 0; i < 10; i++) {
			if (v[i] != 0) {
				for (int j = 0; j < v[i]; j++) cout << "*";
				cout << endl;
			}
			else cout << "-" << endl;
		}
	}

	

	


	return 0;
}