#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int digit(long long int a)
{	
	int  ans = 0;
	while(a > 0){
		a/=10;
		ans++;
	}

	return ans;
}


int main() {
	int i;
	int count = 1;
	long long int N, A = 1, B;
	int ans = 15;

	cin >> N;

	while ((double)A <= sqrt((double)N))
	{
		if (N % A == 0)
		{
			B = N/A;
			count = max(digit(A),digit(B));
			if (ans > count)
			{
				ans = count;
			}
			
		}
		A++;
	}

	
	cout << ans <<endl;

}