#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long a;
	double b;
	cin>> a >>b;
	unsigned long long c = 1000*b;
	unsigned long long d = a*c;
	unsigned long long e = d/1000;
	cout<< e <<endl;
}