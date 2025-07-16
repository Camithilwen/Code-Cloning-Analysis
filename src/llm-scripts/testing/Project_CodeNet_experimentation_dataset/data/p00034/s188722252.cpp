#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, v1, v2, sum, i;
	double ter;
	vector<int> s;
	while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &v1, &v2) != EOF) {
		s.clear();
		s.push_back(l1);
		s.push_back(l2);
		s.push_back(l3);
		s.push_back(l4);
		s.push_back(l5);
		s.push_back(l6);
		s.push_back(l7);
		s.push_back(l8);
		s.push_back(l9);
		s.push_back(l10);
		sum = l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10;
		ter = (double(sum*v1)) / (v1 + v2);
		sum = 0;
		for (i = 0; i < 10; i++) {
			sum += s[i];
			if (ter <= (double)sum) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}