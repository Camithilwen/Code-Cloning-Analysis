#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int n,g=0; cin>>n;
while(n>=3)
{
    g++; n-=3;
}
cout<<g;
return 0;
}