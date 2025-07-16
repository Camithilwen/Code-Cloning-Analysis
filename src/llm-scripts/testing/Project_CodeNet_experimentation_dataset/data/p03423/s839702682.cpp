#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
//const int N = 1e3 + 5;
int main(){

	int n,d=0,t=0,count=0;
	cin >> n;
	if (0 <= n&&n <= 2){
		cout << 0 << endl;
		return 0;
	}
	while (n)
	{
		n -=3;
		if (n >= 3)
			count++;
		else{
			count++;
			break;
            }
		
	}
	cout << count << endl;





}