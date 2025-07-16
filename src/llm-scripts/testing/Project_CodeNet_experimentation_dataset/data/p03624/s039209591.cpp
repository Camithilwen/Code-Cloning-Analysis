#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	string s;
	set<int> m2;
	vector<int> result;
	cin>>s;
	for(int i = 0; i < s.length(); i++){
		int num = s[i] - 'a';
		if(m2.count(num) == 0) m2.insert(num);
	}
	
	for(int i = 0; i < 26; i++){
		if( m2.count(i) == 0) result.push_back(i);
	}
	if( result.size() == 0){
		cout<<"None"<<endl;
	}else{
		cout<<(char)(result[0] + 'a')<<endl;
	}
	return 0;
}

