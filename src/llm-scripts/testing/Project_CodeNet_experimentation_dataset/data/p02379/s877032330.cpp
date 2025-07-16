#include<stdio.h>
#include<math.h>

int main(){
	double a,b,c,d;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	printf("%.8lf\n",sqrt(pow(c-a,2.0)+pow((d-b),2.0)));
}