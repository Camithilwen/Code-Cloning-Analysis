#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> p[2];
	int tmp;
	for(int j=0;j<2;j++){
	for(int i=0;i<10;i++){
		cin >> tmp;
		p[j].push_back(tmp);
	}
	sort(p[j].begin(),p[j].end(),greater<int>());
	int sum=0;
	for(int i=0;i<3;i++)
	sum+=p[j][i];
	cout << sum;
	if(!j)
	cout << " ";
	else
	cout << endl;
	}
	// your code goes here
	return 0;
}