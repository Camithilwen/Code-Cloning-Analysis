#include <iostream>
#include <algorithm>
using namespace std;

int main(){


int score[20]={};


for(int i=0;i<10;i++){
  cin >> score[i];
 }
 sort(score, score+10);


 int score2[20]={};

for(int i=0;i<10;i++){
  cin >> score2[i];
 }
 sort(score2,score2+10);

int  sum1=score[9]+score[8]+score[7];
int  sum2=score2[9]+score2[8]+score2[7];

 cout << sum1 << ' '<< sum2 << endl;

}