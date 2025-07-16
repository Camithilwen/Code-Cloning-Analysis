#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int alfabet[26] = {0};
	for (int i = 0; i < S.length(); i++) {
		alfabet[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alfabet[i] == 0) {
			printf("%c\n", 'a' + i);
			return 0;
		}
	}
	printf("None\n");
	return 0;

}
