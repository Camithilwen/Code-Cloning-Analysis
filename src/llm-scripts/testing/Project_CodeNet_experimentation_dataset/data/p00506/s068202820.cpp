#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long int i, fin, num[3];
int n;

int main(){

	cin >> n;
	for(i=0;i<n;i++){
		cin >> num[i];
	}

	if(n==2){
		fin = min(num[0], num[1]);
		for(i=1;i<=fin;i++){
			if(!(num[0]%i) && !(num[1]%i)){
				cout << i << endl;
			}
		}
	}

	if(n==3){
		fin = min(num[0], num[1]);
		fin = min(num[2], fin);
		for(i=1;i<=fin;i++){
			if(!(num[0]%i) && !(num[1]%i) && !(num[2]%i)){
				cout << i << endl;
			}
		}
	}

	return 0;
}