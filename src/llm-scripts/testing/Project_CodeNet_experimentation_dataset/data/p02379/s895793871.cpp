#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iomanip>
 
using namespace std;
 
string in, t;
double a, b, c, d;
 
 
int main(){
    cin >> a >> c >> b >> d;
    cout << fixed << setprecision(5) << sqrt(fabs(a - b)*fabs(a - b)*1.0 + fabs(c - d)*fabs(c - d)*1.0) << endl;
}