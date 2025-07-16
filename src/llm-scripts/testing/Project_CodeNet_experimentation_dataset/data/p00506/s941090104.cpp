#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int gcd(int a, int b){
	while(b){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(){
	list<int> ls;
	list<int>::iterator it = ls.begin();

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	a = gcd(a, b);
	if(n == 3) a = gcd(a, c);

	for(int i = 1; i * i <= a; ++i){
		if(a % i == 0){
			ls.insert(it, i);
			if(i * i < a) it = ls.insert(it, a / i);
		}
	}
	
	copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, "\n"));
}