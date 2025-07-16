#include<cstdint>
#include<limits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	int n,h,w;
	std::cin>>n>>h>>w;
	std::cout<<1+(n-h)+(n-w)+(n-h)*(n-w);
}
