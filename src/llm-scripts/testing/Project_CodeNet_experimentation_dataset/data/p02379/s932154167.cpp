#include<stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    double x1,y1,x2,y2,x3,y3; 
    cin>>x1>>y1>>x2>>y2;
    x3=pow(x1-x2,2);
    y3=pow(y1-y2,2);
    printf("%f",sqrt(x3+y3));
    return 0;
}

