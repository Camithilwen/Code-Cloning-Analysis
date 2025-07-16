
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;
#define p 1000000 

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);


	while(1){
		long long int n,tmp[3],cnt = 0;
		vector<long long int> number;
		vector<long long int> sales;
		vector<long long int> flg;
		cin >> n;
		if(n == 0) break;
		for(int i=0; i<4000; i++) {
			sales.push_back(0); 
			flg.push_back(0);
		}
		for(int i=0; i<n; i++) {
			cin >> tmp[0] >> tmp[1] >> tmp[2];
			sales.at(tmp[0]) += tmp[1]*tmp[2];
			if(flg.at(tmp[0]) == 1) continue;
			number.push_back(tmp[0]);
			flg.at(tmp[0]) = 1;
		}
		for(int i=0; i<number.size(); i++) {
			if(sales.at(number.at(i)) >= p) {
				cout << number.at(i) << endl;
				cnt++;
			}
		}
		if(cnt == 0) {
			cout << "NA" << endl;
		} 
	}

	//while(1){}
	return 0;
}