#define	_USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <set>
using namespace std;
int main(){
	
	int n;
	int a,b,c,d;
	cin>>n;
	vector<int> sum(n+1,0);
	vector<int> rank(n+1);
	sum[0]=-999999;
	for(int i=0;i<n*(n-1)/2;i++){
		cin>>a>>b>>c>>d;
		if(c>d){
			sum[a]+=3;
		}
		else if(c<d)
			sum[b]+=3;
		else{
			sum[a]++;
			sum[b]++;
		}	
	}
	int k=0;
	int o=0;
	for(int i=0;i<n;i++){
		vector<int>::iterator it=find(sum.begin(),sum.end(),*max_element(sum.begin(),sum.end()));
		int j=it-sum.begin();
		if(k==0){
			k=1;
			o=sum[j];
			rank[j]=1;
		}
		else if(o==sum[j]){
			rank[j]=k;
		}
		else{
			k=i+1;
			o=sum[j];
			rank[j]=k;
		}
		sum[j]=-999999;
	}
	
	for(int i=1;i<=n;i++)
		cout<<rank[i]<<endl;
	
	
	
	
}