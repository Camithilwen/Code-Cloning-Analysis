#include <iostream>
using namespace std;
int main(){
	long long int n,i=1,a=0;
	cin >> n;
	while (i <= n) {
		if (i % 3 != 0 && i % 5 != 0)
			a += i;
		i++;
	}
	cout << a;
}