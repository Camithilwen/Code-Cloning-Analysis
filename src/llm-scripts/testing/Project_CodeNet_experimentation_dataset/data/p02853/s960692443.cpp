#include <iostream>
using namespace std;
int solve(int x){
	if(x == 1) return 3;
	else if(x == 2) return 2;
	else if(x == 3) return 1;
	else return 0;
}
int main() {
	// your code goes here
	int x, y; cin>>x>>y;
	int answer = solve(x);
	answer += solve(y);
	if(x == y && x == 1) answer += 4;
	cout<<answer * 100000;
	return 0;
}