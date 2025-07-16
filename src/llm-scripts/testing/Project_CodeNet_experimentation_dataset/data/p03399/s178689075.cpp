#include<bits/stdc++.h>
using namespace std;

int main(void){
  int AB[2], CD[2], value;
  for(int i = 0; i < 2; i++)
    cin >> AB[i];
  for(int i = 0; i < 2; i++)
    cin >> CD[i];
  sort(begin(AB), end(AB));
  sort(begin(CD), end(CD));
  value = AB[0] + CD[0];
  cout << value << "\n";
  return 0;
}
