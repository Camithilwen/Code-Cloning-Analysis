#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main(){
	int people[21], Total, Total2;
	for (int i = 0; i < 20; i++){
		cin >> people[i];
	}
	sort(people, people + 10,greater<int>());
	sort(people + 10, people + 20,greater<int>());
	Total = people[0] + people[1] + people[2];
	Total2 = people[10] + people[11] + people[12];
	cout << Total <<" "<< Total2 << endl;
	return 0;
}