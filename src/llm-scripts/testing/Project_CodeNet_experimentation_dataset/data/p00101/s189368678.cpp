#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <complex>
using namespace std;
 
const double EPS = 1e-9;
const double PI = 3.14159265359;
 
typedef complex<double> P;

typedef long long int li;

int main(){
	int n;
	string hos = "Hoshino";

	cin >> n;
	cin.ignore();
	while(n--){
		string s;
		getline(cin, s);

		int k = s.size()+1-hos.size();
		for(int i = 0; i < k; i++){
			if(s.substr(i, hos.size()) == hos){
				s[i+hos.size()-1] = 'a';
			}
		}

		cout << s << endl;
	}

    return 0;
}