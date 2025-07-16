#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
 
using namespace std;
 
int main(void){
	
	int n;
	cin >> n;

	for( int i = 0; i < n; i++ ) {
		int outs = 0, runner = 0, pts = 0;
		while( outs < 3 ) {
			string evt;
			cin >> evt;
			if( evt == "HIT" ) {
				if( runner < 3 ) {
					runner ++;
				} else {
					pts ++;
				}
			} else if( evt == "OUT" ) {
				outs ++;
			} else {
				pts += runner + 1;
				runner = 0;
			}
		}
		cout << pts << endl;
	}

	return 0;
}