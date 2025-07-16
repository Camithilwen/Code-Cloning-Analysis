#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int p = 0;
		int oc = 0;
		int rui[4] = {1,0,0,0};
		while(1){
			string s;
			getline(cin,s);
			if(s=="OUT") oc++;
			else if(s=="HIT"){
				if(rui[3]==1) p++;
				for(int j=3;j>0;j--) rui[j] = rui[j-1];
			}
			else if(s=="HOMERUN"){
				for(int j=1;j<4;j++){
					if(rui[j]==1) p++;
					rui[j] = 0;
				}
					p++;
			}
			if(oc==3) break;
		}
		cout << p << endl;
	}
}