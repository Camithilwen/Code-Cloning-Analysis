#include <bits/stdc++.h>

using namespace std;

int main(){
	pair<double,double> p1,p2;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	double dis;
	dis=sqrt(pow(p2.first-p1.first,2.0)+pow(p2.second-p1.second,2.0));
	printf("%f\n",dis);
	return 0;
}