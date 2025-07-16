#include <iostream>

using namespace std;

int main(int argc, char** argv){
	int n, pm, pe, pj;
	
	while( 1 ){
		cin >> n;
		if(n==0) break;
		
		for(int i=0; i<n; i++){
			cin >> pm;
			cin >> pe;
			cin >> pj;
			
			if(pm==100 || pe==100 || pj==100){
				cout << "A" << endl;
				continue;
			}
			
			if((pm+pe) / 2 >= 90){
				cout << "A" << endl;
				continue;
			}
			
			int avg = (pm + pe + pj) / 3;
			if(avg >= 80){
				cout << "A" <<endl;
				continue;
			}
			
			if(avg >= 70){
				cout << "B" << endl;
				continue;
			}
			
			if(avg>=50 && pm>=80){
				cout << "B" << endl;
				continue;
			}
			
			cout << "C" << endl;
		}
	}
	
	return 0;
}