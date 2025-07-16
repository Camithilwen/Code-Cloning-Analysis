#include <bits/stdc++.h>
using namespace std;
 
int rr[8], cc[8];
int r[8], c[8];


int main(){
  int k;
  cin >> k;
  int count=0;
  for(int i=0;i<k;i++) cin >> r[i] >> c[i];

  
  
  for(int co=0;co<pow(8,8-k);co++)
  {
    for(int i=0;i<8;i++)
    {
      rr[i]=-1;
      cc[i]=-1;
    }
    //無理やり配置を用意して
   
    for(int i=0;i<8;i++)
    {
      rr[i]=i;
      if(i<k) cc[r[i]]=c[i];
    }
    int hoge=0;
    for(int i=0;i<8;i++)
    {
      int a=pow(8,hoge);
      if(cc[i]==-1)
      {
        cc[i]=co%(a*8)/a;
        hoge++;
      }
    }
    //襲撃をtrueで埋めて
    bool masu[8][8]{false};
    for(int i=0;i<8;i++)
    {
      for(int j=1;j<8;j++)
      {
        if(cc[i]-j>=0) masu[rr[i]][cc[i]-j]=true;
        if(cc[i]+j<=7) masu[rr[i]][cc[i]+j]=true;
        if(rr[i]-j>=0) masu[rr[i]-j][cc[i]]=true;
        if(rr[i]+j<=7) masu[rr[i]+j][cc[i]]=true;
        
        if(rr[i]-j>=0&&cc[i]-j>=0) masu[rr[i]-j][cc[i]-j]=true;
        if(rr[i]+j<=7&&cc[i]-j>=0) masu[rr[i]+j][cc[i]-j]=true;
        if(rr[i]-j>=0&&cc[i]+j<=7) masu[rr[i]-j][cc[i]+j]=true;
        if(rr[i]+j<=7&&cc[i]+j<=7) masu[rr[i]+j][cc[i]+j]=true;
      }
    }
    
    count=0;
    for(int j=0;j<8;j++)
    {
      if(masu[rr[j]][cc[j]]==false) count++;
    }
    //cout << count << endl; 
    if(count==8)
    {
      count=0;
      
      for(int j=0;j<k;j++)
      {
        if(c[j]==cc[r[j]]) count++;
      }
      
      if(count==k)
      {
        break;
        //return 0;
      }
    }
  }
  for(int i=0;i<8;i++)
        {
          for(int j=0;j<8;j++)
          {
            if(cc[i]==j) cout << 'Q';
            else cout <<'.';
          }
          cout << endl; 
        }
  //cout << "hoge"<< endl; 
  return 0;
}
