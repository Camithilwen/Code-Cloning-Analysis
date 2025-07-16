#include <iostream>
#include <algorithm>
using namespace std;

int straight(int card[])
{
	for(int i=1; i<9; i++){
		if(((card[0]==i)&&(card[1]==i+1)&&(card[2]==i+2)&&(card[3]==i+3)&&(card[4]==i+4)) || 
			(card[0]==1&&card[1]==10&&card[2]==11&&card[3]==12&&card[4]==13))
			return 1;
	}
	return 0;
}

int main(){
	int c[5], n;
	char k;

	while(1){
		cin>>c[0]>>k>>c[1]>>k>>c[2]>>k>>c[3]>>k>>c[4];
		if(cin.eof())break;
		n=0;
		sort(c, c+5);

		for(int i=0; i<4; i++){
			for(int j=i+1; j<5; j++){
				if(c[i]==c[j])
					n++;
			}
		}
		switch(n){
			case 1:
				cout<<"one pair\n";
				break;
			case 2:
				cout<<"two pair\n";
				break;
			case 3:
				cout<<"three card\n";
				break;
			case 4:
				cout<<"full house\n";
				break;
			case 6:
				cout<<"four card\n";
				break;
			case 10:
				cout<<"four card\n";
				break;
			default:
				if(straight(c))
					cout<<"straight\n";
				else
					cout<<"null\n";
				break;
		}
	}

	return 0;
}