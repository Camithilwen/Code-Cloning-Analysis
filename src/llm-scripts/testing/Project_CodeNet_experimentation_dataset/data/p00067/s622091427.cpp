#include <iostream>
using namespace std;

bool cell[12][12];

void search(int i, int j){
	if(i<0 || i>11 || j<0 || j>11) return;
	if(cell[i][j]) cell[i][j] = false;
	else return;
	search(i+1, j);
	search(i-1, j);
	search(i, j+1);
	search(i, j-1);
}

int main(){
	while(1){
		int ans = 0;

		//ÇÝÝ
		bool flag = false;
		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				char buf;
				if(!(cin >> buf)){
					flag = true;
					break;
				}
				buf -= '0';
				if(buf) cell[i][j] = true;
				else cell[i][j] = false;
			}
			if(flag) break;
		}
		if(flag) break;

		//Tõ
		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				if(cell[i][j]){
					search(i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
}