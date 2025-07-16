#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n,ground,ou,point;
  string s;
  
  scanf("%d",&n);
  
  for(int cas=0;cas<n;cas++){
    ground = ou = point = 0;
    while(1){
      cin >> s;
      if(s == "OUT"){
	ou++;
	if(ou == 3) break;
      } else if(s == "HIT"){
	ground<<=1;
	ground|=1;
	if(ground >= (1<<3)){
	  ground&=(~(1<<3));
	  point++;
	}
      } else{
	for(int i=0;i<3;i++){
	  if(ground&(1<<i)) point++;
	}
	ground=0;
	point++;
      }
    }
    cout << point << endl;
  }
  
  return 0;
}