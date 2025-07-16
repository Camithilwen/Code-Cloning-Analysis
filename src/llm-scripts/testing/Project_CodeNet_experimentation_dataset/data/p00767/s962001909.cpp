#include<iostream>
using namespace std;
int main(){
  int h,w;
  while(1){
    cin>>h>>w;
    if(h==0)break;
    int d=h*h+w*w,ah=100,aw=100;
    for(int i=1;i<=150;i++)
      for(int j=i+1;j<=150;j++){
	int k=i*i+j*j;
	if(((k==d&&i>h)||k>d)&&(ah*ah+aw*aw>k||(k==ah*ah+aw*aw&&ah>i)))ah=i,aw=j;
 }
    cout<<ah<<' '<<aw<<endl;
  }
  return 0;
}