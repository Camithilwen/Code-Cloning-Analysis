#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;
#define FOR(I,F,N) for(int I = F; I < (int)(N); I++)
#define rep(i, n) FOR(i, 0, n)
#define FIN(V) cout<<V<<endl
#define pb push_back
#define INF (1 << 30)
typedef pair<int, int> P;
typedef long long ll;
typedef priority_queue<int> pq;
int StrToInt(string);
string IntToStr(int);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
	int n;
	while(cin >> n){
		int mat, eng, jap;
		rep(i, n){
			cin >> mat >> eng >> jap;
			int sum = mat + eng + jap;
			if(mat == 100 || eng == 100 || jap == 100 || sum >= 240 || sum-jap >= 180){
				cout << "A" << endl;
				continue;
			}else if(sum >= 210||(sum >= 150 && (mat >= 80 || eng >= 80))){
				cout << "B" << endl;
				continue;
			}else{
				cout << "C" << endl;
			}
		}
	}

	return 0;
}



int StrToInt(string s){
	stringstream ss;
	ss << s;
	int val;
	ss >> val;
	return val;
}
string IntToStr(int i){
	stringstream ss;
	ss << i;
	return ss.str();
}