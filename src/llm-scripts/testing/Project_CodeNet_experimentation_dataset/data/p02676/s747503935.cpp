#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	char arr[100];
	cin >> k;
	scanf("%s", arr);
	if(strlen(arr) <=k){
		printf("%s", arr);
	}
	else{
		for(int i=0; i<k; ++i){
			cout << arr[i];
		}
		cout << "...";
	}
}
