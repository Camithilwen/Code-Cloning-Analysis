#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> card(5);
	vector<int> count(13);
	string handName[7] = {"null", "one pair", "two pair", "three card", "straight", "full house", "four card"};
	int hand;
	int max, pair;
	int i;

	while (scanf("%d,%d,%d,%d,%d", &card[0], &card[1], &card[2], &card[3], &card[4]) != EOF) {
		fill(count.begin(), count.end(), 0);
		max = 0;
		pair = 0;
		for (i = 0; i < 5; i++) {
			if ( ++count[card[i]-1] > max )
				max = count[card[i]-1];
			if ( count[card[i]-1] == 2 )
				pair++;
		}

		if (max == 4) hand = 6;
		else if (max==3 && pair==2) hand = 5;
		else if (max == 3) hand = 3;
		else if (pair == 2) hand = 2;
		else if (pair == 1) hand = 1;
		else hand = 0;
		if (hand < 4) {
			for (i = 0; i < 13-3; i++) {
				if (count[i]==1 && count[i+1]==1 && count[i+2]==1 && count[i+3]==1 && count[(i+4)%13]==1)
					hand = 4;
			}
		}

		cout<<handName[hand]<<endl;
	}
	return 0;
}