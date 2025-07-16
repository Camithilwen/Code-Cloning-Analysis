#include <iostream>
using namespace std;
int main(){
  int n; cin >>n;
  for(int i = n; i < 1000; i++){
    if(i % 111 == 0){
		cout << i << endl;
      	return 0;
    }
  }
}