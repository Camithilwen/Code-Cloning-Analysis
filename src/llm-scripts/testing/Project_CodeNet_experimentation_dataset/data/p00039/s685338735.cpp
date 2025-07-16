#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	string st;
	map<char, int>mp;
	mp['I'] = 0;
	mp['V'] = 1;
	mp['X'] = 2;
	mp['L'] = 3;
	mp['C'] = 4;
	mp['D'] = 5;
	mp['M'] = 6;
	
	vector<int>values{ 1,5,10,50,100,500,1000 };
	while (cin >> st) {
		vector<int>nums;
		for (auto c : st) {
			nums.push_back(mp[c]);
		}
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i == nums.size() - 1 || nums[i] >= nums[i + 1])sum += values[nums[i]];
			else sum -= values[nums[i]];
		}
		cout << sum << endl;

	}
	return 0;
}