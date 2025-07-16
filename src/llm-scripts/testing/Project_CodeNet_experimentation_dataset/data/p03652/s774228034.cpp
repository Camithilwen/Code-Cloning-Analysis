#include <bits/stdc++.h>
using namespace std;

int N,M;
int FS[310][310];
vector<int>K;
  
int main(){
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>FS[i][j];
    }
  }
  for(int i=1;i<=M;i++){
    K.push_back(i);
  }
  int eachmaxcnt=0;
  int maxcnt=300;
  int C[310];
  int temp=0;
  
  //ゲームの種類分回す
  for(int i=0;i<M;i++){
    
    //各ゲームの参加者数を初期化
    for(int i=1;i<=M;i++){
      C[i]=0;
    }
      for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
          //最初にでてくるゲームの参加者を加算
          if(FS[i][j] != -1){
            C[FS[i][j]]++;
            break;
          }
        }
    }
    
    //最大参加者数を求める
    eachmaxcnt=0;
    for(int i=1;i<=M;i++){
      if(eachmaxcnt<C[i]){
        eachmaxcnt=C[i];
        temp=i;
      }
    }

    //最大参加者数の更新
    maxcnt=min(maxcnt,eachmaxcnt);
    
    //最大参加者のゲームを-1にする
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(FS[i][j]==temp){
          FS[i][j]=-1;
        }    
      }
    }
  }    

  cout<<maxcnt<<endl;
  return 0;
}