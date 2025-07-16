#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, a, b, c;
	vector<char>l;
	while (true){
		cin >> n;
		if (n == 0){
			break;
		}
		else{
			for (int i = 0; i < n; i++){
				cin >> a >> b >> c;
				if (a == 100 || b == 100 || c == 100){
					l.push_back('A');
				}
				else if (a + b >= 180){
					l.push_back('A');
				}
				else if (a + b + c >= 240){
					l.push_back('A');
				}
				else if (a + b + c >= 210){
					l.push_back('B');
				}
				else if (a + b + c >= 150 && a >= 80){
					l.push_back('B');
				}
				else if (a + b + c >= 150 && b >= 80){
					l.push_back('B');
				}
				else l.push_back('C');
				a = 0;
				b = 0;
				c = 0;
			}
		}
	}
	for (int i = 0; i != l.size(); i++)
	{
		cout << l[i] << endl;
	}
}