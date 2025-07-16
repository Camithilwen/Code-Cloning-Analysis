#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Dice
{
private:
  int surf[6];
public:
  void set_surf(int* input);
  void roll(char orient);
  void disp_top();
};

void Dice::set_surf(int* input)
{
  memcpy(surf, input, 6*sizeof(int));
}

void Dice::roll(char orient){
  int temp[6];
  
  switch(orient){
  case 'S':
    temp[0]=surf[4];
    temp[1]=surf[0];
    temp[2]=surf[2];
    temp[3]=surf[3];
    temp[4]=surf[5];
    temp[5]=surf[1];
    break;
  case 'N':
    temp[0]=surf[1];
    temp[1]=surf[5];
    temp[2]=surf[2];
    temp[3]=surf[3];
    temp[4]=surf[0];
    temp[5]=surf[4];
    break;
  case 'W':
    temp[0]=surf[2];
    temp[1]=surf[1];
    temp[2]=surf[5];
    temp[3]=surf[0];
    temp[4]=surf[4];
    temp[5]=surf[3];
    break;
  case 'E':
    temp[0]=surf[3];
    temp[1]=surf[1];
    temp[2]=surf[0];
    temp[3]=surf[5];
    temp[4]=surf[4];
    temp[5]=surf[2];
    break;
  }

  memcpy(surf, temp, 6*sizeof(int));
  
}

void Dice::disp_top(){
  cout << surf[0] << endl;
}

int main()
{
  int input[6];
  Dice dice;
  string order;
  
  for(int i=0; i<6; i++){
    cin >> input[i];
  }
  dice.set_surf(input);
  
  cin >> order;

  for(int i=0; i<order.size(); i++){
    dice.roll(order[i]);
  }

  dice.disp_top();
  
  return(0);
}