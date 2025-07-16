#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> hand(5);
  char c;
  
  while(cin >> hand[0]>>c>>hand[1]>>c>>hand[2]>>c>>hand[3]>>c>>hand[4]){
    vector<int> cnt(15, 0);
    for(int i=0; i<5; i++){
      cnt[hand[i]]++;
      if(hand[i] == 1) cnt[14]++;
    }
    bool flag = false;

    // four card
    for(int i=1; i<=13; i++){
      if(cnt[i] == 4){
        cout << "four card" << endl; flag = true;
      }
    }
    if(flag) continue;

    // three card or full house
    for(int i=1; i<=13; i++){
      if(cnt[i] == 3){
        for(int j=1; j<=13; j++){
          if(cnt[j] == 2){
            cout << "full house" << endl; flag = true;
          }
        }
        if(flag) break;
        cout << "three card" << endl; flag = true;
      }
    }
    if(flag) continue;

    // two pair or one pair
    for(int i=1; i<=13; i++){
      if(cnt[i] == 2){
        for(int j=i+1; j<=13; j++){
          if(cnt[j] == 2){
            cout << "two pair" << endl; flag = true;
          }
        }
        if(flag) break;
        cout << "one pair" << endl; flag = true;
      }
    }
    if(flag) continue;

    // straight
    for(int i=1; i<=13; i++){
      if(cnt[i] == 1 && cnt[i+1] == 1 && cnt[i+2] == 1 && cnt[i+3] == 1 && cnt[i+4] == 1){
        cout << "straight" << endl; flag = true;
      }
    }
    if(flag) continue;

    //null
    cout << "null" << endl;
  }

}
  
  
