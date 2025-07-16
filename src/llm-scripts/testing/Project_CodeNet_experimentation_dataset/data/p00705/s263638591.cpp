#define _USE_MATH_DEFINES
#define INF 100000000

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

static const double EPS = 1e-8;

int main(){
	int N,Q;
	while(~scanf("%d %d",&N,&Q)){
		if(N==0 && Q==0) break;
		map<int,int> freq;
		for(int i=0;i<N;i++){
			int num;
			scanf("%d",&num);

			for(int j=0;j<num;j++){
				int day;
				scanf("%d",&day);
				freq[day]++;
			}
		}

		int maxv=0;
		int min_day=INF;
		for(map<int,int>::iterator it = freq.begin(); it!=freq.end();it++){
			if(it->second >= Q){
				if(maxv < it->second){
					maxv = it->second;
					min_day=it->first;
				}
				else if(maxv == it->second){
					min_day=min(min_day,it->first);
				}
			}
		}

		printf("%d\n",min_day >= INF ? 0 : min_day);
	}
}