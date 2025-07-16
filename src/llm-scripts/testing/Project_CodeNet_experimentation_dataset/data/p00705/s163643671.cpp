#include <iostream>

using namespace std;

int hi[101];

int main() {
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
	    int no = 0, yes = 0;
	    for (int i = 1; i <= 101; i++) hi[i] = 0;
	    for (int i = 0; i < a; i++) {
	        int x; cin >> x;
	        for (int o = 0; o < x; o++) {
	            int yay; cin >> yay;
	            hi[yay]++;
	        }
	    }
	    for (int i = 101; i > 0; i--) {
	        if (yes <= hi[i] && hi[i] >= b) {
	            no = i;
	            yes = hi[i];
	        }
	    }
	    cout << no << endl;
	    cin >> a >> b;
	}
}

