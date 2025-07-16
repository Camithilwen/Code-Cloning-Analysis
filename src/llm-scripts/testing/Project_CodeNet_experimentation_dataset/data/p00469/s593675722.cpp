#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int N,K;
  while( cin >> N >> K){
    if( N == 0 && K == 0){ break;}
    vector<string> P(N);
    for(int i = 0; i < N; i++){ int c; cin >> c; P[i] = to_string(c);}
  
   
    set<string> s;  
    
    if( K == 2){
      for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
          vector<string> vec;
          vec.push_back(P[i]); vec.push_back(P[j]);
          sort(vec.begin(),vec.end());
        do{
          s.insert(vec[0]+vec[1]);
        }while(next_permutation(vec.begin(),vec.end()));
        
        }}}
    
    if( K == 3){
      for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
          for(int k = j+1; k < N; k++){
            
          vector<string> vec;
          vec.push_back(P[i]); vec.push_back(P[j]); vec.push_back(P[k]);
          sort(vec.begin(),vec.end());
        do{
          s.insert(vec[0]+vec[1]+vec[2]);
        }while(next_permutation(vec.begin(),vec.end()));
        
            
           
          }
        }
      }
    }
    
    if( K == 4){
      for(int i = 0; i < N-3; i++){
        for(int j= i+1; j < N-2; j++){
          for(int k = j+1;k < N-1; k++){
            for(int l = k+1; l < N; l++){
         vector<string> vec;
          vec.push_back(P[i]); vec.push_back(P[j]); vec.push_back(P[k]); vec.push_back(P[l]);
          sort(vec.begin(),vec.end());
        do{
          s.insert(vec[0]+vec[1]+vec[2]+vec[3]);
        }while(next_permutation(vec.begin(),vec.end()));
        
            }
          }
        }
      }
    }
    cout << s.size() << endl;
  }
    
  
  return 0;}
      

