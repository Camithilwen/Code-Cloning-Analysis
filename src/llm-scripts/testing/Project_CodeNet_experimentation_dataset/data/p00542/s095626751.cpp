#include <bits/stdc++.h>

using namespace std;

vector<int> SubjectsInfo;

int main() {
	int score;

	for (int i = 0; i < 6; ++i) {
		cin >> score;
		SubjectsInfo.push_back(score);
	}
	sort(SubjectsInfo.begin(), SubjectsInfo.begin() + 4);
	cout << SubjectsInfo[1] + SubjectsInfo[2] + SubjectsInfo[3] + max(SubjectsInfo[4], SubjectsInfo[5]) << endl;

	return 0;
}
