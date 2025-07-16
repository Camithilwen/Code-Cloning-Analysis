#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
int r;
int x;
cin >> n;
cin >> r;
x = 100*(10-n)+r;
if (n >= 10) {
  cout << r;
} else {
 cout << x; 
}
	return 0;
}
