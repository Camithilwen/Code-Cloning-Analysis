#include <iostream>
#include <stdio.h>
#include <math.h>

//I は1, V は5, X は10, L は50, C は100, D は500, M は1000,

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

using namespace std;

int main(){

	string str;
	while(cin>>str){
		int data[200];
		int sum = 0;
		
		//データの数値化
		for(int i=0;i<str.size();i++){
			switch(str[i]){
				case 'I':
					data[i]=I;
					break;
				case 'V':
					data[i]=V;
					break;
				case 'X':
					data[i]=X;
					break;
				case 'L':
					data[i]=L;
					break;
				case 'C':
					data[i]=C;
					break;
				case 'D':
					data[i]=D;
					break;
				case 'M':
					data[i]=M;
					break;
			}
		}

		for(int i=0;i<str.size();i++){
			if(i==str.size()-1){
				sum+=data[i];
			}
			else{
				if(data[i]<data[i+1]){
					sum+= (data[i+1]-data[i]);
					i++;
				}
				else{
					sum+=data[i];
				}
			}
		}

		cout<<sum<<endl;
	}

	return 0;

}

/*
IV
CCCCLXXXXVIIII
CDXCIX
*/