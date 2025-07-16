#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

long long N;
string name;

int main(){
	cin >> N;
	while (N != 0){
		N--;
		name += ('a' + (N % 26));
		N /= 26;
	}

	reverse(name.begin(), name.end());
	cout << name << endl;

	return 0;
}