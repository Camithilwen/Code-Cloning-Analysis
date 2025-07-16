#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int card[5], cnt, max_cnt, min_cnt, cnt_one;
	char cnm;

	while(cin >> card[0]){
		cnt = 1;
		for(int i=1; i<9; i++){
			if(i % 2 == 0){
				cin >> card[cnt];
				cnt++;
			}
			else cin >> cnm;
		}
		
		sort(card, card + 5);
		max_cnt = 1;
		min_cnt = 5;
		cnt_one = 0;
		cnt = 1;
		for(int i=0; i<4; i++){
			if(card[i] == card[i+1]) cnt++;
			else {
				min_cnt = min(min_cnt, cnt);
				if(cnt == 1) cnt_one++;
				cnt = 1;
			}
			max_cnt = max(max_cnt, cnt);
		}
		if(card[3] != card[4]) cnt_one++;

		if(max_cnt == 4) cout << "four card" << endl;
		else if(max_cnt == 3){
			if(min_cnt == 1) cout << "three card" << endl;
			else cout << "full house" << endl;
		}
		else if(max_cnt == 2){
			if(cnt_one == 3) cout << "one pair" << endl;
			else cout << "two pair" << endl;
		}
		else if(card[0] + 4 == card[4] || (card[0] == 1 && card[1] == 10)){
			cout << "straight" << endl;
		}
		else cout << "null" << endl;
	}

	return 0;

}