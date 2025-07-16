#include<iostream>
	#include<stdlib.h>
	#include<math.h>
	#include<algorithm>
	#include<string.h>
	using namespace std;


	int main()

	{
		std::ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		int n; cin >> n;
		for  (int i = 1; ;  i++){
			if (i * i == n) {
				cout << i * i << endl;
				break;
			}
			if (i * i > n) {
				i--;
				cout << i * i << endl;
				break;
			}


		}
		
		return 0;
	
}