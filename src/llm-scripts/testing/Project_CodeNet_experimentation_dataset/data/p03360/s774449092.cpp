#include<iostream>
using namespace std;

int angka [10], brpkali, total;

int main (){
	for (int i=1; i<=3; i++){
		cin>>angka[i];
	}
	cin>>brpkali;
	for (int i=1; i<=3; i++){
		for (int j=1; j<=3; j++){
			if (j==i){
			}else if (angka [i]>angka [j]){			//sort;
				swap(angka [i], angka [j]);
			}
		}
	}
	for (int i=1; i<=brpkali; i++){				//multipy big num
		angka [1]*=2;
	}
	for (int i=1; i<=3; i++){					//sum total
		total+=angka [i];
	}
	cout<<total<<endl;
}