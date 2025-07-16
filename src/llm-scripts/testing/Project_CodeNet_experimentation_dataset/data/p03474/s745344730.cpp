#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B;
	string S;
	cin >> A >> B;
	cin >> S;


	// 文字列の長さがA+B+1か判定
	if (S.size() != A + B + 1) {
		// cout << "文字列の長さが" << S.size() << "です。\n";
		cout << "No\n";
		return 0;
	}

	// -がA番目にあるか判定(文字列は0からスタート)
	if (S.find('-') != A) {
		// cout << "-(ハイフン)は" << S.find('-') << "番目にあります。\n";
		cout << "No\n";
		return 0;
	}

	// A+1番目の文字以外が0から9であるか判定
	for (int i = 0; i < S.size(); i++) {
		// cout << "S[" << i << "]は" << S[i] << "です。\n";
		if (i == A) {
			continue;
		}
		if (S[i] > '9' || S[i] < '0') {
			// cout << "0-9以外の文字が含まれています。\n";
			cout << "No\n";
			return 0;
		} 
	}

	cout << "Yes\n";
	return 0;
}