#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <cstring> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int n;
	while(1){
		cin >> n;
		if(n == 0) break;
		int key[200];
		char s[200], right_s[200], ch;
		for(int i = 0; i < n; i++){
			cin >> key[i];
		}
		ch = getchar();
		fgets(s, sizeof(s), stdin);
		int wronglist[200]={0}, rightlist[200];
		for(int i = 0; i < strlen(s)-1; i++){
			wronglist[i] = s[i] - 'A';
			if(wronglist[i] > 25) wronglist[i] -= 6;
			rightlist[i] = wronglist[i] - key[i%n];
			if(rightlist[i] < 0) rightlist[i] = 52 + rightlist[i];
			if(rightlist[i] > 25) rightlist[i] += 6;
			right_s[i] = rightlist[i] + 'A';
		}
		right_s[strlen(s)-1] = '\0';
		cout << right_s << endl;
	}
	return 0;
}