#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
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
typedef pair <int,P > PP;

int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};

static const double EPS = 1e-8;

struct Jinfo{
	int start;
	int len;
};

int main(){
	string str;
	while(cin >> str){
		int res = 0;

		deque<char> jdeq;
		deque<char> odeq;
		deque<char> ideq;

		int onum=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='J'){
				if(odeq.size() > 0
					|| ideq.size() > 0){
						odeq.clear();
						ideq.clear();
						jdeq.clear();
				}
				
				jdeq.push_back(str[i]);
			}

			else if(str[i]=='O'){
				if(ideq.size() > 0){				
					jdeq.clear();
					odeq.clear();
					ideq.clear();
				}
				odeq.push_back(str[i]);
			}

			else if(str[i]=='I'){
				ideq.push_back(str[i]);
			}

			if(ideq.size() > 0
				&& odeq.size() > 0
				&& jdeq.size() > 0
				&& jdeq.size() >= odeq.size()
				&& ideq.size() >= odeq.size()){
					res = max(res,(int)odeq.size());
					jdeq.clear();
					ideq.clear();
					odeq.clear();
			}



		}

		printf("%d\n",res);
	}
}