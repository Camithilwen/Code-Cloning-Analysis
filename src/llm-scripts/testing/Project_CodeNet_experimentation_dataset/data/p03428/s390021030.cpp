#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
double naiseki(pair<double,double> v1,pair<double,double> v2){
	return v1.first*v2.first+v1.second*v2.second;
}
int main(){
	int N;
	int x[101],y[101];
	pint ab[101][101];
	vector<double> kakudo[101];
	scan(N);
	rep(i,N){
		scan(x[i]);scan(y[i]);
	}
	if(N==2){
		prin(0.5),prin(0.5);
	}
	else{
		rep(i,N){
			rep(j,N){
				if(i==j) continue;
				else{
					ab[i][j]=mp(x[i]-x[j],y[i]-y[j]);
					if(naiseki(mp(x[i]-(double)(x[i]+x[j])/2,y[i]-(double)(y[i]+y[j])/2),ab[i][j])<0){
						ab[i][j]=mp(x[j]-x[i],y[j]-y[i]);
					}
				}
				//printf("i:%d j:%d ab:(%d,%d) naiseki:%f\n",i,j,ab[i][j].first,ab[i][j].second,naiseki(mp(x[i]-(double)(x[i]+x[j])/2,y[i]-(double)(y[i]+y[j])/2),ab[i][j]));
			}
		}
		rep(i,N){
			rep(j,N){
				if(i==j) continue;
				kakudo[i].push_back(atan2((double)ab[i][j].second,(double)ab[i][j].first));
				//printf("i:%d j:%d kakudo:%f(%f)\n",i,j,kakudo[i].back(),kakudo[i].back()*180/M_PI);
			}
			sort(kakudo[i].begin(),kakudo[i].end());
			int flag=0;
			double thetamin,thetamax;
			rep(j,kakudo[i].size()){
				if(j==0){
					if(kakudo[i][0]+M_PI*2-kakudo[i].back()>=M_PI){
						flag=1;
						thetamin=kakudo[i][0],thetamax=kakudo[i].back();
					}
				}
				else{
					if(kakudo[i][j]-kakudo[i][j-1]>=M_PI){
						flag=1;
						thetamin=kakudo[i][j],thetamax=kakudo[i][j-1];
						if(thetamin>thetamax) thetamax+=M_PI*2;
					}
				}
			}
			//printf("i: max:%f min:%f\n",thetamax,thetamin);
			if(flag){
				prin((M_PI-(thetamax-thetamin))/(M_PI*2));
			}
			else{
				prin(0.0);
			}
		}
	}
	return 0;
}
