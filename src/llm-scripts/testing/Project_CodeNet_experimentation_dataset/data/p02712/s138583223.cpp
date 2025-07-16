#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
  	cin >> n;
 	long long res = 0;
  	for(int i=0;i<n;i++){
    	int a = i+1;
      	if(a % 3 == 0 || a % 5 == 0) continue;
      	else res += a;
    }
  	cout << res << endl;
}