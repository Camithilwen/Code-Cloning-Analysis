#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int len[10];
	int v1,v2;
	while( scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &len[0],&len[1],&len[2],&len[3],&len[4],&len[5],&len[6],&len[7],&len[8],&len[9],&v1,&v2) != EOF ){
		int accum[10] = {0};
		accum[0] = len[0];
		for(int i=1;i<10;i++){
			accum[i] += accum[i-1] + len[i];
		}
		
		// accum[9] は合計の距離
		double t = (double)accum[9]/(v1 + v2);
		double dist = (double) v1*t;
		for(int i=0;i<10;i++){
			if( dist <= accum[i] ){
				cout<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}