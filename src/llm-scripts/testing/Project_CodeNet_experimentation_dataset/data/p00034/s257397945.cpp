#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const double EPS = 1e-9;

int main(){
	int l[10], v[2];
	while(scanf("%d,", &l[0])!=EOF){
		for(int i=1; i<10; i++){
			scanf("%d,", &l[i]);
		}
		scanf("%d,%d", &v[0], &v[1]);
		
		int total=0;
		for(int i=0; i<10; i++){
			total += l[i];
		}
		
		double t = (double)total/(v[0]+v[1]);
		double d = v[0]*t -EPS;
		int sum=0;
		for(int i=0; i<10; i++){
			sum += l[i];
			if(sum > d){
				cout << i+1 << endl;
				break;
			}
		}
	}
    return 0;
}