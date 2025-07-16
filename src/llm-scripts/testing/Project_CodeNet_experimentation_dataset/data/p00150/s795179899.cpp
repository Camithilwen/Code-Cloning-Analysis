#include<iostream>
#include<string>
using namespace std;

bool primenumver(int a){
	for (int b = 2;; b += 2) {
		if (a%b == 0)return false;
		if ((b + 1)*(b+ 1) >a)return true;
		if (b == 2)b--;
	}
}
int main() 
{
	while (1) {
		int a;
		cin >> a;
		if (a == 0)break;
		if (a % 2 == 0) {
			for (int b = a-1;; b -= 2) {
				if (primenumver(b) && primenumver(b - 2)) { cout << b - 2 << " " << b<<endl; break; }
			}
		}
		else {
			for (int b = a;; b -= 2) {
				if (primenumver(b) && primenumver(b - 2)) { cout << b - 2 << " " << b<<endl; break; }
			}
		}
	}
}