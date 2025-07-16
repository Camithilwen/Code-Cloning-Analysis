#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<stdio.h>

using namespace std;

int ans, Jcou, Ocou, Icou;
char letter, target='A';


int main(){

	while(1){
		scanf("%c", &letter);
		if(letter == '\n'){break;}

		if(target == 'A' && letter == 'J'){
			Jcou = 1;
			Ocou = 0;
			Icou = 0;
			target = 'J';
		}

		else if(target == 'J'){
			if(letter == 'J'){
				Jcou++;
			}
			else if(letter == 'O'){
				Ocou++;
				target = 'O';
			}
			else if(letter == 'I'){
				target = 'A';
			}
		}

		else if(target == 'O'){
			if(letter == 'J'){
				target = 'J';
				Jcou = 1;
				Ocou = 0;
				Icou = 0;
			}
			else if(letter == 'O'){
				Ocou++;
			}
			else if(letter == 'I'){
				if(Jcou < Ocou){
					target = 'A';
				}
				else{
					target = 'I';
					Icou++;
					if(Ocou == Icou){
						ans = max(ans, Icou);
						target = 'A';
					}
				}
			}
		}

		else if(target == 'I'){
			if(letter == 'J'){
				if(Ocou<=Icou){
					ans = max(ans, Ocou);
					target = 'J';
					Jcou = 1;
					Ocou = 0;
					Icou = 0;
				}
				else{
					target = 'J';
					Jcou = 1;
					Ocou = 0;
					Icou = 0;
				}
			}
			else if(letter == 'O'){
				if(Ocou <= Icou){
					ans = max(ans, Ocou);
					target = 'A';
				}
				else{
					target = 'A';
				}
			}
			else if(letter == 'I'){
//				cout << "I in" << endl;
				Icou++;
				if(Ocou==Icou){
					ans = max(ans, Icou);
					target = 'A';
				}
			}
		}

//		cout << Jcou << " " << Ocou << " " << Icou << " " << endl;

	}

	cout << ans << endl;

	return 0;
}