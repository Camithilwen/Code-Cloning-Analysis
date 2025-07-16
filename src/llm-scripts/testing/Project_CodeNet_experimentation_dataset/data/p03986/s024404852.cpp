#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
long long INF = (1LL<<62);

string X;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> X;
	string s;

	for(int i=0; i<X.size(); i++){
		if(i == 0){
			s.push_back(X[i]);
		}
		else{
			if(s[s.size()-1] == 'S' && X[i] == 'T'){
				s.pop_back();
			}
			else{
				s.push_back(X[i]);
			}
		}
	}
	printf("%d\n", (int)s.size());
	return 0;
}