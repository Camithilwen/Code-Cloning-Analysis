#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void){

	string roman;
	string fig("IVXLCDM");
	int ure[]={1,5,10,50,100,500,1000};
	int sum;
	while(cin>>roman){
		sum=0;
		for(int i=1;i<roman.length();i++){
			if(ure[fig.find(roman[i])]>ure[fig.find(roman[i-1])]) sum+=-1*ure[fig.find(roman[i-1])];
			else sum+=ure[fig.find(roman[i-1])];
		}
		sum+=ure[fig.find(roman[roman.length()-1])];
		cout<<sum<<endl;
	}

	return 0;
}