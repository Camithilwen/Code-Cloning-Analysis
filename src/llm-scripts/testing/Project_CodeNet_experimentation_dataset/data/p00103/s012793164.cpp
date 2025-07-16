#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstdio>
typedef unsigned long long ull;
#define rep(i,a) for(int i=0;i<a;i++)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1);
const double inf = (int)1e8;

int main(void){
  string str;
  int base=0,point=0,out=0;
  int n;
  cin>>n;
  getline(cin,str);
  while(getline(cin,str)){
    if(str[0] == 'O'){
      out++;
      //cout<<out<<endl;
      if(out==3){
	n--;
	printf("%d\n",point);	
	base=0,point=0,out=0;
	if(n==0)break;
      }
    }
    else if(str[1] == 'I'){
      base ++;
      if(base>3){
	base --;
	point ++;
      }
    }
    else if(str[1] == 'O'){
      point += base + 1;
      base = 0;
    }

  }
  return 0;
}