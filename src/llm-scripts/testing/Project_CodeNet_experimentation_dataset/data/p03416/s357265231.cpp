#include<iostream>
#include<string>
#include<vector>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int keta(int i) {
	int ret=0;
	while (i > 0) {
		i /= 10;
		ret++;
	}
	return ret;

}
void ita(int y, vector<int> *x) {
	int i = x->size()-1;
	while (y > 0) {
		x->at(i--) = y % 10;
		y /= 10;
	}
}
int main() {
	int a, b;
	cin >> a >> b;
	int count = 0;
	for (int i = a; i <= b; i++) {
		vector<int> x(keta(i));
		ita(i, &x);
		int l = 0, r = x.size() - 1;
			while (x.at(l++) == x.at(r--)) {
				if (l > r) {
					count++;
					break;
				}
			}
		
	}
	cout << count << endl;
}