#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>ans = { 2,7,17,37,47,67,97,107,127,137,157,167,197,227,257,277,307,317,337,347,367,397,457,467,487,547,557,577,587,607,617,647,677,727,757,787,797,827,857,877,887,907,937,947,967,977,997,1087,1097,1117,1187,1217,1237,1277,1297,1307 };
	for (int i = 0; i < n; i++) {
		if (i == 0)cout << ans.at(i);
		else cout << " " << ans.at(i);
	}
}