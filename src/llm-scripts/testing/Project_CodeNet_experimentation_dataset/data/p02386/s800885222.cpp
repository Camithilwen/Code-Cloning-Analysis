#include<iostream>
using namespace std;

int main()
{
	int n;
	int i, j, k, l, m;
	int tmp;
	int count=0;
	
	cin >> n;
	int Dice[n][6];
	
	for(i=0;i<n;i++){
		for(j=0;j<6;j++){
			cin >> Dice[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=0;k<4;k++){
				tmp=Dice[j][0];
				Dice[j][0]=Dice[j][1];
				Dice[j][1]=Dice[j][5];
				Dice[j][5]=Dice[j][4];
				Dice[j][4]=tmp;
				if(Dice[j][1]==Dice[i][1])
					goto Break;
				else{
					for(l=0;l<4;l++){
						tmp=Dice[j][0];
						Dice[j][0]=Dice[j][3];
						Dice[j][3]=Dice[j][5];
						Dice[j][5]=Dice[j][2];
						Dice[j][2]=tmp;
						if(Dice[j][0]==Dice[i][1]){
							tmp=Dice[j][0];
							Dice[j][0]=Dice[j][4];
							Dice[j][4]=Dice[j][5];
							Dice[j][5]=Dice[j][1];
							Dice[j][1]=tmp;
							goto Break;
						}
					}
				}
			}
			Return:;
		}
	}
	goto Exit;
	
	Break:;
	for(m=0;m<4;m++){
		tmp=Dice[j][0];
		Dice[j][0]=Dice[j][3];
		Dice[j][3]=Dice[j][5];
		Dice[j][5]=Dice[j][2];
		Dice[j][2]=tmp;
		if(Dice[j][0]==Dice[i][0]){
			if(Dice[i][0]==Dice[j][0]&&Dice[i][1]==Dice[j][1]&&Dice[i][2]==Dice[j][2]&&Dice[i][3]==Dice[j][3]&&Dice[i][4]==Dice[j][4]&&Dice[i][5]==Dice[j][5]){
				cout << "No" << endl;
				return 0;
			}
			else{
				goto Return;
			}
		}
	}
	goto Return;
	
	Exit:;
	cout << "Yes" << endl;
	return 0;
}