#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	printf("%.6f\n",sqrt(pow(bx-ax,2)+pow(by-ay,2)));
    return 0;
}