#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

long long x;
cin >> x;

long long happiness=0;
long long a,b,c;

a=x/500;
b=x%500;
c=b/5;

cout << a*1000+c*5 << endl;


	return 0;
}









