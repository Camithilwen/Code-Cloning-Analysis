#include <iostream>
using namespace std;

int main() {
	int X, Y; 
    cin >> X >> Y;
	if (X < 9 && Y <9){
      cout << "Yay!" << endl;
      return 0;
    }
	cout << ":(" << endl;
}
