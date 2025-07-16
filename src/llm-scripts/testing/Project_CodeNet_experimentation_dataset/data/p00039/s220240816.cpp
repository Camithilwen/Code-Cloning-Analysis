#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const string ara = "IVXLCDM\0";
const int integer[8] = {1,5,10,50,100,500,1000}; 
int Input(int num[],string in);
void Output(int p,int num[]);
 
int main(void){
  string in;
  int num[1000];

  while( cin >> in ){
    for(int i = 0 ; i < 1000; i++)num[i] = 0;
    int p = Input(num,in);
    Output(p,num);
  }
  return 0;
}

int Input(int num[],string in){

  int p = 0;
  for(int i = 0 ; i < (int)in.size(); i++){
    for(int j = 0 ; ara[j] != '\0'  ; j++ ){
      if(in[i] == ara[j]){
	num[p++] = integer[j];
	break;
      }
    }
  }
  return p;
}

void Output(int p,int num[]){
  int ans  = 0;
  for(int i = 0 ;i < p ; i++){

    if(num[i] < num[i+1]){
      ans += (num[i+1] - num[i]);
      i++;
    } else ans+=num[i];
  }
  cout << ans << endl;
}