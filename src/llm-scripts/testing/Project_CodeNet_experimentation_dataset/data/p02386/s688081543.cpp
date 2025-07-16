#include<bits/stdc++.h>
using namespace std;
int n;
class Dice{
private:
  int right,left,front,back,bottom,now,flag=1;
  int role(int num[6],int num2[6],string str){
    for(int i=0;i<str.size();i++){
      if(num[0]==num2[0]&&num[1]==num2[1]&&num[2]==num2[2]&&num[3]==num2[3]&&num[4]==num2[4]&&num[5]==num2[5]){
	cout<<"No"<<endl;
	flag=0;
	return 0;
      }
      switch(str[i]){
      case 'S':num[1]=now;num[0]=back;num[4]=bottom;num[5]=front;now=num[0];back=num[4];bottom=num[5];front=num[1];break;
      case 'W':num[3]=front;num[1]=right;num[2]=back;num[4]=left;front=num[1];left=num[3];back=num[4];right=num[2];break;
      case 'E':num[3]=bottom;num[0]=left;num[2]=now;num[5]=right;now=num[0];left=num[3];bottom=num[5];right=num[2];break;
      case 'N':num[4]=now;num[0]=front;num[1]=bottom;num[5]=back;now=num[0];back=num[4];bottom=num[5];front=num[1];break;
      }
      if(num[0]==num2[0]&&num[1]==num2[1]&&num[2]==num2[2]&&num[3]==num2[3]&&num[4]==num2[4]&&num[5]==num2[5]){
	cout<<"No"<<endl;
	flag=0;
	return 0;
      }
    }
  }
public:
  void Scan(int num[100][6]){
   
    for(int i=0;i<n-1;i++){
      now=num[i][0];right=num[i][2];left=num[i][3];front=num[i][1];back=num[i][4];bottom=num[i][5];
      for(int j=i+1;j<n;j++){    
	role(num[i],num[j],"WWWNWWWWNWWWWNWWWNWWWWNNWWWNWWW");
	if(flag==0)
	  return;
      }
    }
    if(flag==1)
      cout<<"Yes"<<endl;
  }
};

int main(){
  Dice dice;
  int a,b;
  cin>>n;
  int num[100][6];
  for(int i=0;i<n;i++)
    for(int j=0;j<6;j++)
      cin>>num[i][j];
  dice.Scan(num);
  return 0;
}