#include<iostream>

using namespace std;

int main() {
  int x,m,n;
	while(cin >> x){
	  n=0;
	  m = 600/x;
	  for(int i = 1;i<m;i++){
	    n += x*x*x*i*i;
	  }

	  cout << n << endl;
	}
	return 0;
}

