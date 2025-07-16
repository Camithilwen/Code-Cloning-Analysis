#include<iostream>
using namespace std;

int main(){
int a;
int uma;
int ushi;
int b;
int c;
int i;
while (true){
cin >> a;
if (a == 0){ break; }
else{
	while (true){
	if (i<a){
	cin >> b;
	cin >> c;
	if (b>c){
		uma = uma + b + c;
	}
	else if (b == c){
		uma = uma + b;
		ushi = ushi + c;
	}
	else{
	ushi = ushi + b + c;
	}
	i = i + 1;
}if (i == a){ break; }
}
cout << uma << " " << ushi << endl;
uma = 0;
ushi = 0;
i = 0;
}
}
}