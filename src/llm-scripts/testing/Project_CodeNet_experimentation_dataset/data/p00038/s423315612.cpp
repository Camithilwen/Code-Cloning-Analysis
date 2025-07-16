#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  vector<int> hands;
  int tmp;

  while(cin >> tmp){
	hands.push_back(tmp);
	cin.ignore();
	cin >> tmp;
	hands.push_back(tmp);
	cin.ignore();
	cin >> tmp;
	hands.push_back(tmp);
	cin.ignore();
	cin >> tmp;
	hands.push_back(tmp);
	cin.ignore();
	cin >> tmp;
	hands.push_back(tmp);

	sort(hands.begin(), hands.end());
	if(hands[0] == hands[3] || hands[1] == hands[4]){ //four card
	  cout << "four card" << endl;
	}else if((hands[0] == hands[1] && hands[2] == hands[4]) ||
			 (hands[0] == hands[2] && hands[3] == hands[4])){ //full house
	  cout << "full house" << endl;
	}else if((hands[0]+1 == hands[1] && hands[1]+1 == hands[2] && hands[2]+1 == hands[3] && hands[3]+1 == hands[4]) ||
			 (hands[0] == 1 && hands[1] == 10 && hands[2] == 11 && hands[3] == 12 && hands[4] == 13)){
	  cout << "straight" << endl;
	}else if(hands[0] == hands[2] || hands[1] == hands[3] || hands[2] == hands[4]){//three cards
	  cout << "three card" << endl;
	}else if((hands[0] == hands[1] && (hands[2] == hands[3] || hands[3] == hands[4])) || (hands[1] == hands[2] && hands[3] == hands[4])){//two pairs
	  cout << "two pair" << endl;
	}else if(hands[0] == hands[1] || hands[1] == hands[2] || hands[2] == hands[3] || hands[3] == hands[4]){
	  cout << "one pair" << endl;
	}else{
	  cout << "null" << endl;
	}

	hands.clear();
  }


  return 0;
}