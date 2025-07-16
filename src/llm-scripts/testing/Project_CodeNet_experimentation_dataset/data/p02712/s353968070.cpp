#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	long long N;
	cin >> N;
	long long result = 0;
	
	for(long long i = 1;i<=N;i++){
		if(i % 3 != 0 && i % 5 != 0){
			result += i;
		}
		
	}
	
	std::cout << result << endl; 	
	return 0;
	
}
