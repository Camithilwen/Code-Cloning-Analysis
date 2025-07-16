#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	int a[1000] = {};
	int b[1000] = {};
	int point[1000] = {};
	int selected;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[j] <= b[i]){
				point[j]++;
				break;
			}
		}
	}

	selected = 0;
	for(int i = 1; i < n; i++){
		
		if(point[selected] < point[i]){
			selected = i;
		}
	}

	cout << selected + 1 << endl;
	return 0;
}