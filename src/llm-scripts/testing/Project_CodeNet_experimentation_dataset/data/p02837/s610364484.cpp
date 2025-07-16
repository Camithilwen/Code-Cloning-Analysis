# include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x,y;
  int ans=0;
  cin>>N;
  int A[N];//証言の数
  vector<pair<int,int>>T[N];
   
  //証言を入力  
  for(int i=0;i<N;i++){
    cin>>A[i];
    for(int j=0;j<A[i];j++){
      cin>>x>>y;
      x--;
      T[i].push_back({x,y});
    }
  }
  
  //bit全探索
  for(int i=0;i<(1<<N);i++){
    int cnt=0;//正直者の数
    for(int j=0;j<N;j++){
      if(i & (1<<j)){
        cnt++;
      }
    }
    
    int flag=1;
    for(int j=0;j<N;j++){
      if(i & (1<<j)){     
        //jが正直者として証言が矛盾しないかチェック　矛盾したらflag=0でbreak;
        for(int k=0;k<A[j];k++){
          if(i & 1<<(T[j].at(k).first)){
            if(T[j].at(k).second==1){
              continue;
            }
            else{
              flag=0;
              break;
            }
          }
          else{
            if(T[j].at(k).second==0){
              continue;
            }
            else{
              flag=0;
              break;
            }
          }
        }
      }
    }
    if(flag){
      ans=max(ans,cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}
