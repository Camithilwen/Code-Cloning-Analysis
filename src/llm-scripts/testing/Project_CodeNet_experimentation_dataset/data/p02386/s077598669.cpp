#include <iostream>
#include <vector>

using namespace std;

class Dice
{
  public:
    vector<int> diceNum;
    Dice(vector<int>& inputs);
    void toW();
    void toS();
    void ParallelRotation();
};

Dice::Dice(vector<int>& inputs)
{
  diceNum=inputs;
}

void Dice::toW()
{
  swap(diceNum[0],diceNum[3]);
  swap(diceNum[0],diceNum[5]);
  swap(diceNum[0],diceNum[2]);
}

void Dice::toS()
{
  swap(diceNum[0],diceNum[1]);
  swap(diceNum[0],diceNum[5]);
  swap(diceNum[0],diceNum[4]);
}

void Dice::ParallelRotation()
{
  swap(diceNum[1],diceNum[2]);
  swap(diceNum[2],diceNum[4]);
  swap(diceNum[4],diceNum[3]);
}

bool Judge(Dice& dice1,Dice& dice2)
{
  int count=0;
  for(int i=0;i<6;i++)
  {
    if(dice1.diceNum[i]==dice2.diceNum[i]) count++;
  }
  if(count==6)return true;
  else return false;
    
}

bool preJudge(Dice& dice1,Dice& dice2)
{
  int count=0;
  bool flag=false;
  while(1)
  {
    dice2.toS();
    for(int j=0;j<4;j++)
    {
      dice2.ParallelRotation();
      flag=Judge(dice1,dice2);
      if(flag==true) break;
    }
    if(flag==true) break;
    dice2.toW();
    for(int j=0;j<4;j++)
    {
      dice2.ParallelRotation();
      flag=Judge(dice1,dice2);
      if(flag==true) break;
    }
    count++;
    if(flag==true) break;
    if(count==3)break;
  } 
  return flag;
}

int main(int argc,char* argv[])
{
  vector<int> inputs(6);
  int number;
  int count =0;
  cin >> number;
  bool flag=false;
  
  vector<Dice> Dices;
  for(int i=0;i<number;i++)
  {
    for(int j=0;j<6;j++)
    {
      cin >> inputs[j];
    }
    Dices.push_back(Dice(inputs));
  }
  for(int i=0;i<number-1;i++)
  {
    for(int j=i+1;j<number;j++)
    {
      flag = preJudge(Dices[i],Dices[j]);
      if(flag==true) break;
    }
    if(flag==true) break;
  }
  if(flag==true) cout << "No" << endl;
  else if(flag==false) cout << "Yes" << endl;
}