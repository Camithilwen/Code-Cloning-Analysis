#include <iostream>
#include <string>
using namespace std;
typedef struct{
	string id;
	long long sales;
} staff;

int main(void)
{
	long long n;
	while(cin>>n){
		if(!n) break;
		staff staff1[4001];
		int pt = 0;
		for(int i=0; i< n; i++){
			string id;
			cin >> id;
			long long price;
			int bnum;
			cin >> price >> bnum;
			int m=-1;
			for(int j=0;j < i; j++){
				if(id==staff1[j].id){
					pt++;
					m=j;
					break;
				}
			}
			if(m==-1){
				staff1[i-pt].id = id;
				staff1[i-pt].sales = price * bnum;
			}else{
				staff1[m].sales += price * bnum;
			}
		}
		int count = 0;
		for(int i=0; i < n-pt; i++){
			if(staff1[i].sales >= 1000000){
				count++;
				cout << staff1[i].id << endl;
			}
		}
		if(!count) cout << "NA" << endl;
	}
	
	return 0;
}