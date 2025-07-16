//ALDS1_13_A
#include <iostream>
#include <vector>
using namespace std;

void printChess(int chess[]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j == chess[i])
				cout<<"Q";
			else
				cout<<".";
		}
		cout<<endl;
	}
}

bool isBlank(int chess[], int &r){
	for(int i=0;i<8;i++){
		if(chess[i] == 100){
			r = i;
			return true;
		}
	}
	return false;
}

bool setQ(int chess[], int r, int c){
	for(int i=0;i<8;i++){
		if(chess[i] == c)
			return false;
		if(i+chess[i] == r+c)
			return false;
		if(i-chess[i] == r-c)
			return false;
	}
	return true;
}

void solve(int chess[]){
	int r;
	if(isBlank(chess, r)){
		for(int c=0;c<8;c++){
			if(setQ(chess, r, c)){
				chess[r] = c;
				solve(chess);
				chess[r] = 100;
			}
		}
	}else{
		printChess(chess);
	}
}

int main(){
	int k, r, c, chess[8];
	
	for(int i=0;i<8;i++)
		chess[i] = 100;

	cin>>k;
	for(int i=0;i<k;i++){
		cin>>r>>c;
		chess[r] = c;
	}

	solve(chess);

	return 0;
}