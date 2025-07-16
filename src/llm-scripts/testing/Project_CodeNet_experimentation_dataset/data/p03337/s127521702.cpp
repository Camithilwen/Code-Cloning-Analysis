#include <iostream>
using namespace std;

int a,b,sum,dif,tim;

int main(){
	cin >> a >> b;
	sum = a + b;
	dif = a - b;
	tim = a * b;
	if((sum > dif)&&(sum > tim)){
		cout << sum;
	}else{
		if(dif > tim){
			cout << dif;
		}else{
			cout << tim;
		}
	}
	cout << endl;
}