#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a[4], b[2], sum;
	
	sum = 0;
	
	for (int i = 0; i < 4; i++){
		cin >> a[i];
	}
	
	cin >> b[0] >> b[1];
	
	if (b[0] <= b[1]){
		sum += b[1];
	}
	else {
		sum += b[0];
	}
	
	
	sort(a, a + 4);
	
	sum += a[1] + a[2] + a[3];
	
	cout << sum << endl;
}