#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> a;
vector<string> b(4);
string st;


bool dfs(int i, int sum, int n) {

	if (i == 0) {
		sum = sum + a[0];
		i++;
	}

	if (i == n) {
		if (sum == 7) {
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					cout << st[j];
					continue;
				}
				cout << b[j] << st[j];
			}
			cout << "=" << sum << endl;
			return true;
		}
		else{
			return false;
        }
    }

	b[i] = "+";
	if (dfs(i + 1, sum + a[i], n)) return true;

	b[i] = "-";
	if (dfs(i + 1, sum - a[i], n)) return true;
  
    return false;
}

int main(void) {

	cin >> st;
	for (int i = 0; i < 4; i++)
		a.push_back(st[i] - '0');

	bool a = dfs(0, 0, 4);


}