#include<iostream>
using namespace std;

int getDate(int q,int array[]){
	int max=0,key=0;
	for(int i=0;i<100000;i++){
		if(max<array[i]){
			max = array[i];
			key = i;
		}
	}
	return (max >= q) ? key : 0;
}	


int main(){
	int n,q;
	int array[100000];
	while(1){
		cin >> n >> q;
		if(n+q==0) break;
		for(int i=0;i<100000;i++)
			array[i]=0;
		for(int i=0;i<n;i++){
			int m, date;
			cin >> m;
			for(int j=0;j<m;j++){
				cin >> date;
				array[date]++;
			}
		}
		cout << getDate(q,array) << endl;
	}

}