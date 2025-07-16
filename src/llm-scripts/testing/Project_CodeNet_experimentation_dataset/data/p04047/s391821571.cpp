#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
  	cin >> n;
  	vector <int> L(2*n);
  
  	for (int i=0; i<L.size(); i++)
      	cin >>  L[i];
  	
  	sort (L.begin(), L.end());
  	int res = 0;
  	for (int i=0; i<L.size(); i+=2) {
    	res += min (L[i], L[i+1]);
    }
  
  	cout << res;
  
}