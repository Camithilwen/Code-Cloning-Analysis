#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	double row[10],v[2];
	for(;;){
		if (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&row[0],&row[1],&row[2],&row[3],&row[4],&row[5],&row[6],&row[7],&row[8],&row[9],&v[0],&v[1]) == EOF){break;}
		int i;
		double t,dis = 0,d = 0;
		for(int i=0; i<10; i++){
			dis+=row[i];
		}
		for(i=0; i<10; i++){
			d+=row[i];
			t = d/v[0];
			if(dis <= t*(v[0]+v[1])){break;}
		}
		cout<<i+1<<endl;
	}
	return 0;
}