#include <iostream>
using namespace std;

bool include3(int n){
	while(n!=0){
		if(n%10==3){
			return true;
		}
		n = n /10;
	}
	return false;
}

void call(int n){
	for(int i = 1; i <= n; i++){
		if( i % 3 == 0 || include3(i) ){
			cout << " " << i;
		}
	}
	cout << endl;
}

int main()
{
	int num;
	cin>>num;
	call(num);
	return 0;
}