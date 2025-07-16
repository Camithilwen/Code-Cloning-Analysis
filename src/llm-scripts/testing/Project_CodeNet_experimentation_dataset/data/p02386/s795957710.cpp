#include <bits/stdc++.h>
using namespace std;

void dice_roll( int *dice, char i){
	if( i == 'W'){
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
	if( i == 'S'){
		int tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	if( i == 'D'){
		int tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	if( i == 'A'){
		int tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	if( i == 'd'){
		int tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[3];
		dice[3] = tmp;
	}
}
int checkdice(int *d1, int *d2){
	int b = 0;
	for(int i = 0; i < 4; i++){
		dice_roll(d1, 'W');
		for(int j = 0; j < 4; j++){
			dice_roll(d1, 'D');
			for(int k = 0; k < 4; k++){
				dice_roll(d1, 'd');
				if(d1[0]==d2[0]&&d1[1]==d2[1]&&d1[2]==d2[2]&&d1[3]==d2[3]&&d1[4]==d2[4]&&d1[5]==d2[5]){
					return 1;
					i=4;j=4;k=4;
					b= 1;
				}
			}
		}
	}
	if(b!=1)return 0;
}
int main(){
	/*
		0
	3	1	2	4
		5
	*/
	int n;
	cin >> n;
	int d[n][6];
	string s = "Yes";
	for(int i = 0; i < n; i++){
		for(int j = 0; j< 6; j++) cin >> d[i][j];
	}
	for(int h = 0; h < n; h++){
		for(int i = 0; i < n; i++){
			int t1[] = { d[h][0],d[h][1],d[h][2],d[h][3],d[h][4],d[h][5] };
			int t2[] = { d[i][0],d[i][1],d[i][2],d[i][3],d[i][4],d[i][5] };
			if(h!=i){
			int t = checkdice(t1,t2);
				if(t==1){
					s = "No";
				}
			}
		}
	}
	cout << s <<endl;
	return 0;
}

