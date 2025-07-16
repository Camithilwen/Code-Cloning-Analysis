#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ll n,a,b;
	cin >> n >> a >> b;
	int x[n];
	for (int i=0;i<n;i++) cin >> x[i];
	ll c=0;
	for (int i=0;i<n-1;i++) {
		if ((x[i+1]-x[i])*a>b) c+=b;
		else c+=a*(x[i+1]-x[i]);
	}
	cout << c;
}