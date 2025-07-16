#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
int main(){
  for(;;){
    vector<int> lot(5);
    int ans = 0;
    if(scanf("%d",&lot[0]) == EOF) break;
    for(int i=1; i<5; i++) scanf(",%d",&lot[i]);
    sort(lot.begin(),lot.end());
    map<int,int> card;
    for(int i=0; i<5; i++) card[lot[i]]++;
    for(map<int,int>::iterator it = card.begin(); it!=card.end(); it++){
      if(it->second == 2) ans+=2; 
      if(it->second == 3) ans+=3;
      if(it->second == 4) ans+=6;
    }
    if(ans == 2) cout <<"one pair"<<endl;
    if(ans == 3) cout <<"three card"<<endl;
    if(ans == 4) cout <<"two pair"<<endl;
    if(ans == 5) cout <<"full house"<<endl;
    if(ans == 6) cout <<"four card"<<endl;
    if(lot[0]+1 == lot[1] && lot[1]+1 == lot[2] && lot[2]+1 == lot[3] && lot[3]+1 == lot[4]) cout <<"straight"<<endl;
    else if(lot[0] == 1 && lot[1] == 10 && lot[2] == 11 && lot[3] == 12 && lot[4] == 13) cout <<"straight"<<endl;
    else if(ans == 0) cout<<"null"<<endl;
  }
  return 0;
}