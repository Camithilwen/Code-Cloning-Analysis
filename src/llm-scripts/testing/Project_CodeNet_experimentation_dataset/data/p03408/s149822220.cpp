#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  
  int saidai = 0;
  
  int N;
  cin >> N;
  
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    
    cin >> s.at(i);
    
  }
  int M;
  cin >> M;
  
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    
    cin >> t.at(i);
    
  }
  
  for (int i = 0; i < N; i++) {
    
    
    string a = s.at(i);
    int c = 0;
      
      
    for(int i = 0; i < N; i++) {
      
      if (a == s.at(i)) {
        
        c++;
        
      }
      
      
      
    }
    for(int i = 0; i < M; i++) {
      
      if (a == t.at(i)) {
        
        c--;
        
      }
      
      
      
    }
    if (saidai < c) {
      
      saidai = c;
      
    }
    
      
      
   
  }
  
  cout << saidai << endl;
  
}
 
  
  
