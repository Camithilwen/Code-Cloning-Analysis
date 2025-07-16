#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

int main(){
	int a[12];
	while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d"
				,&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10],&a[11]) != EOF){

		int ans = 0;	
		double t = 0, d = 0;
		int sum = 0;
		for(int i = 0;i < 10;i++){
			sum += a[i];
		}
		t = (double)sum / (a[10]+a[11]);
		d = (double)a[10] * t;
		sum = 0;
		for(int i = 0;i < 10;i++){
			sum += a[i];
			if(sum >= d){
				ans = i + 1;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}