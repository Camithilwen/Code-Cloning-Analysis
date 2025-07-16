#include<iostream>
#include<string>
using namespace std;
int data[7];
void N(){int x=data[5];data[5]=data[1];data[1]=data[2];data[2]=data[6];data[6]=x;}
void S(){int x=data[5];data[5]=data[6];data[6]=data[2];data[2]=data[1];data[1]=x;}
void E(){int x=data[3];data[3]=data[1];data[1]=data[4];data[4]=data[6];data[6]=x;}
void W(){int x=data[4];data[4]=data[1];data[1]=data[3];data[3]=data[6];data[6]=x;}
int main(){
  string com;
  for(int i=1;i<=6;++i)cin>>data[i];
  getline(cin,com);
  getline(cin,com);
  for(auto ch:com){
    if(ch=='N')N();
    if(ch=='S')S();
    if(ch=='E')E();
    if(ch=='W')W();
  }
  cout<<data[1]<<endl;
  return 0;
}