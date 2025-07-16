#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <cassert>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 30;
const double EPS = 1e-9;

int nums[200];

int main(){
	int n, q;
	while(cin >> n >> q && (n || q)){
		fill(nums, nums + 200, 0);
		for(int i = 0; i < n; i++){
			int num, date;
			cin >> num;
			for(int j = 0; j < num; j++){
				cin >> date;
				nums[date]++;
			}
		}
		int t = -1;
		int id = 0;
		vector<int> res;
		for(int i = 0; i < 200; i++){
			if(nums[i] >= q){
				if(nums[i] > t){
					t = nums[i];
					id = i;
				}
			}
		}
		if(t == -1){
			cout << 0 << endl;
		}else{
			cout << id << endl;
		}
	}
	return 0;
}