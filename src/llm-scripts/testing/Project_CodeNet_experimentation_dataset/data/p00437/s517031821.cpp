#include<iostream>
#include<vector>

using namespace std;

int main(void){
  int a,b,c,n;
  while(cin>>a>>b>>c,a+b+c){
  cin>>n;
  vector<int> in(a+b+c+1,2);
  vector<vector<int> > jud(n,vector<int>(4,0)); 
  for(int l = 0 ; l < n ; l ++){
    int i , j , k , r;
    cin>>i>>j>>k>>r;
    if(r == 1){
      in[i] = in[j] = in[k] = 1;
    }
    jud[l][0] = i ; jud[l][1] = j ;
    jud[l][2] = k ; jud[l][3] = r;
  }
  
  for(int i = 0 ; i < jud.size() ; i ++){
    if(jud[i][3] == 0){
      if(in[jud[i][0]] == 1 && in[jud[i][1]] == 1) in[jud[i][2]] = 0;
      if(in[jud[i][2]] == 1 && in[jud[i][0]] == 1) in[jud[i][1]] = 0;
      if(in[jud[i][2]] == 1 && in[jud[i][1]] == 1) in[jud[i][0]] = 0;
    }
  }    
  
  for(int i = 1 ; i < in.size() ; i ++)
    cout<<in[i]<<endl;
  }
  return 0;
}