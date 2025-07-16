#include <iostream>
#include <cstdio>
using namespace std;

string s;
int w;
int main() {
	cin >> s >> w;
	for(int i=0; s[i]; i++) {
		if(i%w==0) putchar(s[i]);
	}
	return 0;
}