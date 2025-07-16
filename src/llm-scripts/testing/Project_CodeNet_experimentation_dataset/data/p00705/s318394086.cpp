#include<iostream>
using namespace std;
int member[1000];
bool cp[1000][1000];
int main(){
  int n,q;
  while(cin>>n>>q,n){
    for(int i=0;i<1000;i++)member[i]=0;
    for(int i=0;i<1000;i++)
      for(int j=0;j<1000;j++)cp[i][j]=0;
    for(int i=0;i<n;i++){
      int num;
      cin>>num;
      int tmp;
      for(int j=0;j<num;j++){
	cin>>tmp;
	cp[i][tmp-1]=true;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<1000;j++){
	if(cp[i][j]==true)member[j]++;
      }
    }
    int M=0;
    int ans;
    for(int i=999;i>=0;i--){
      M=max(member[i],M);
      if(member[i] == M){
	ans = i+1;
      }
    }

    if(M>=q){
      cout <<ans << endl;
    }else{
      cout << 0 << endl;
    }
  }
  return 0;
}