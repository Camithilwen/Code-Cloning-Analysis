#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double x1,x2,y1,y2,p;
	cin>>x1>>y1>>x2>>y2;
	
	x1=x2-x1;
	y1=y2-y1;
	
	x1=sqrt(x1*x1+y1*y1);
	
	cout<<setprecision(10)<<x1<<endl;
		
	return 0;
}         