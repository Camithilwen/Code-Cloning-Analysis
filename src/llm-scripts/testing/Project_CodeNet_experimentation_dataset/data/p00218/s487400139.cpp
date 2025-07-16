#define _USE_MATH_DEFINES
#define INF 10000000
#include <iostream>
#include <sstream>
#include <cmath>
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

using namespace std;

typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;

static const double eps = 1e-8;

int getAvr(int* p,int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += p[i];
	}

	return sum/3;
}

int main(){
	int n;	
	while(~scanf("%d",&n)){	
		if(n==0) break;
		
		for(int i=0;i<n;i++){
			int p[3];
			//math,english,japanese			
			scanf("%d %d %d",p,p+1,p+2);

			for(int i=0;i<3;i++){
				if(p[i]==100){
					printf("A\n");
					goto next;
				}
			}

			if(p[0] + p[1] >= 180 || getAvr(p,3) >= 80){
				printf("A\n");
			}

			else if(getAvr(p,3) >= 70
				|| (getAvr(p,3) >= 50 && (p[0] >= 80 || p[1] >= 80))){
				printf("B\n");
			}

			else{
				printf("C\n");
			}
next:;

		}
		
	}
}