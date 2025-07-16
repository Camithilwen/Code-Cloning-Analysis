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


int main(){
	
	int N,Q,M,Date[101],i,l,k;
	
	while(0<=scanf("%d%d",&N,&Q)){
		for(i=0;i<101;i++){
			Date[i]=0;
		}
		
		if((N==0) && (Q==0)){
			break;
		}
		
		for(k=0;k<N;k++){
			scanf("%d",&M);
			if(M==0){
				continue;
			}else{
				for(i=0;i<M;i++){
					scanf("%d",&l);
					++Date[l];
				}
			}
		}
		l=0;
		i=0;
		for(k=0;k<100;k++){
			if(i<Date[k] && Date[k]>=Q){
				i=Date[k];
				l=k;
			}
		}
		
		printf("%d\n",l);
	}
	
	return 0;
}