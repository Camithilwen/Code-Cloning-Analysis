#include<iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();

  int ans = 0;
  for(int i=0;i<n;i++){
    if(s[i] == 'O'){
      int j = 0;
      while( (i+j<n) && (s[i+j] == 'O') )j++;
      
      int k = 0;
      while( (0<=i-1-k) && (k<j) && (s[i-1-k] == 'J'))k++;
      
      int l = 0;
      while( (i+j+l<n) && (l<j) && (s[i+j+l] == 'I'))l++;

      if(j==k && j==l)ans = max(ans,j);

      i += j+l-1;
    }
  }
  cout << ans << endl;
}

      
      