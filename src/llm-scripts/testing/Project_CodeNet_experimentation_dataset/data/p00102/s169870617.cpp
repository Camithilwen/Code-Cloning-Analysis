#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n[102], tn=0,ni=0,all = 0, i = 0,h=0;
	int data[1024][10];
	int tdata[10] = { 0 };
	
	//input
	while (1){
		cin >> n[ni];
		if (n[ni] == 0)break;
		tn += n[ni];

		for (; i < tn; i++){
			for (int j = 0; j < n[ni]; j++){
				cin >> data[i][j];
			}
		}
		ni++;
	}


	//output
	for (int k = 0; k < ni; k++){
		for (int i=0; i < n[k]; i++, all = 0,h++){
			for (int j = 0; j < n[k]; j++){
				printf("%5d", data[h][j]);
				all += data[h][j];
				tdata[j] += data[h][j];
			}
			printf("%5d\n", all);
		}

		all = 0;
		for (int i = 0; i < n[k]; i++){
			printf("%5d", tdata[i]);
			all += tdata[i];
		}
		printf("%5d\n", all);

		for (int i = 0; i < n[k]; i++){
			tdata[i] = 0;
		}
		all = 0;
	}
	return 0;
}