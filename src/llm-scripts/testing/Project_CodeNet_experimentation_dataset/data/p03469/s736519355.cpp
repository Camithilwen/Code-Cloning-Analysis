#include<iostream>

using namespace std;

int main() {
	string str;
	cin >> str;
	//0から4文字分
	str.replace(0, 4, "2018");
	printf("%s", str.c_str());

	return 0;
}
