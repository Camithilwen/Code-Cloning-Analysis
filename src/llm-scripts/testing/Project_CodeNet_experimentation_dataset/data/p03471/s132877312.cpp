#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;


int main(){
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= 2000; i++){
		for (int j = 0; i+j <= 2000; j++){
			for (int k = 0; i+j+k <= 2000; k++){
				if (i+j+k == n && i*1000 + j*5000 + k*10000 == y){
					cout << k << " " << j << " " << i << endl;
					return 0;
				}
			}	
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}

