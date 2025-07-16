#include <iostream>
using namespace std;

int main(){
	double l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
	double v1, v2;
	char c;
	while(cin >> l1 >> c >> l2 >> c >> l3 >> c >> l4
		>> c >> l5 >> c >> l6 >> c >> l7 >> c >> l8
		>> c >> l9 >> c >> l10 >> c >> v1 >> c >> v2)
	{
		double l[] = {
			0,l1,l2,l3,l4,l5,
			l6,l7,l8,l9,l10
		};
		double max_length = l1 + l2 + l3 + l4 + l5
							+l6 + l7 + l8 + l9 + l10;
		for(int i = 1; i <= 10;i++){
			max_length -= (l[i] + (v2 * l[i] / v1));
			if(max_length <= 0){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}