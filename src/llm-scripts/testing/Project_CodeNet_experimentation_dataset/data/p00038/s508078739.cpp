#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void){
  int x[5];
 
  while(scanf("%d,%d,%d,%d,%d"
	       ,&x[0],&x[1],&x[2],&x[3],&x[4])!=EOF){
    sort(x,x+5);

    int cnt[15];
    fill(cnt,cnt+15,0);
    for(int i=0;i<5;i++){
      cnt[x[i]]++;
      if(x[i]==1)cnt[14]++;
    }

    int fg=0;
    for(int i=0;i<15;i++)
      if(cnt[i]==4){
	cout << "four card" << endl;
	fg=1;
	break;;
      }
    if(fg)continue;

    int fg2=0,fg3=0;
    for(int i=0;i<14;i++){
      if(cnt[i]==2)fg2++;
      if(cnt[i]==3)fg3=1;
    }
    if(fg2 && fg3){
      	cout << "full house" << endl;
	continue;
    }

    for(int i=0;i+4<15;i++){
      if(cnt[i] & cnt[i+1] & cnt[i+2] & cnt[i+3] &cnt[i+4]){
	cout << "straight" << endl;
	fg=1;
	break;;
      }
    }
    if(fg)continue;

    if(fg3){
      cout << "three card" << endl;
      continue;
    }

    if(fg2==2){
      cout << "two pair" << endl;
      continue;
    }

    if(fg2==1){
      cout <<"one pair" << endl;
      continue;
    }

    cout << "null" << endl;
  }

  return 0;
}