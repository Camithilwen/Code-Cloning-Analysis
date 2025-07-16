#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int W[10],K[10];
  int score1=0,score2=0;
  for(int i=0;i<10;i++){
    cin >>W[i];
  }
  for(int i=0;i<10;i++){
    cin >>K[i];
  }
  
  sort(W,W+10);
  sort(K,K+10);

  for(int i=9;i>6;i--){
    score1+=W[i];}
  cout <<score1<<" ";
  for(int i=9;i>6;i--){
   score2+=K[i];}
  cout <<score2<<endl;
  return 0;
}