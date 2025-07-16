#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<char, int> P;



int main() {
	string S;
	cin >> S;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	vector<P> vec(26);
	rep(i,26) {
		vec.at(i).first = alpha.at(i);
		vec.at(i).second = 1;
	}
	rep(i, S.size()) {
		rep(j, 26) {
			if (S.at(i)==vec.at(j).first)
			{
				vec.at(j).second = 0;
				break;
			}
		}
	}
	rep(i, 26) {
		if (vec.at(i).second)
		{
			cout << vec.at(i).first << endl;
			return 0;
		}
	}
	cout << "None" << endl;
}