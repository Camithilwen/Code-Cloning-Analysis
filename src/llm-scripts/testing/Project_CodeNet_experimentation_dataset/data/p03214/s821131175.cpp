#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	int n,sum=0,mi_idx;
	double avg,mi=1e9;
	cin >> n;
	vector<int> d(n,0);
	
	for(int i=0;i<n;i++){
		cin >> d[i];
		sum+=d[i];	
	}
	
	avg=(double)sum/(double)n;
	
	for(int i=n-1;i>=0;i--){
		if(mi>=(avg-d[i])*(avg-d[i])){
			mi_idx=i;
		}
		mi=min(mi,(avg-d[i])*(avg-d[i]));
	}
	
	cout << mi_idx << endl;
	return 0;
}
