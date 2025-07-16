#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector <int> vi;
typedef vector <string> vs;
#define N1 5
#define N2 13
int main(void){
	vi card(N2);
	string prize[7]={"null","one pair","two pair","three card","straight","full house","four card"};
	while (true){
		for (int i=0; i<N2; i++)
			card[i]=0;
		int a=0, b=0, d=N2, p=0,tmp;
		for (int i=0;i<N1;i++){
			char c;
			if (i!=0) cin>>c;
			cin>>tmp;
			if (cin.eof()) break;
			tmp--;
			if (tmp<d) d=tmp;
			if (card[tmp]==0) b++;
			card[tmp]++;
			if (card[tmp]>a) a=card[tmp];
		}
		if (b==0) break;
		switch (b){
		case 2: 
			if (a==4) p=6;
			else p=5;
			break;
		case 3:
			if (a==3) p=3;
			else p=2;
			break;
		case 4:
			p=1;
			break;
		case 5:
			bool f=true;
			for (int i=d; i<d+N1; i++)
				if (card[i]!=1){
					f=false;
					break;
				}
			if (!f && card[0]==1){
				f=true;
				for (int i=9; i<N2; i++)
					if (card[i]!=1){
						f=false;
						break;
					}
			}
			if (f) p=4;
			else p=0;
		}
		cout<<prize[p]<<endl;
	}
}