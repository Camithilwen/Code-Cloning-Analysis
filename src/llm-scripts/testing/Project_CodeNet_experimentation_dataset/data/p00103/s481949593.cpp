#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> pint;
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int main(){
	int n;
	cin>>n;
	rep(i,n){
		string str;
		int out=0;
		int rui=0;
		int score=0;
		for(;out<3;){
			cin>>str;
			if(str=="HIT"){
				if(rui==3)score++;
				else rui++;
			}
			if(str=="HOMERUN"){
				score+=rui+1;
				rui=0;
			}
			if(str=="OUT"){
				out++;
			}
		}
		cout<<score<<endl;
	}
	return 0;
}