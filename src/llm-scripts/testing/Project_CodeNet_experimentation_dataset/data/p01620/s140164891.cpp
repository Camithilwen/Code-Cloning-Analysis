#include <iostream>
#include <cctype>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <queue>
#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

char encode(int n){
  if(n < 26) return 'a' + n;
  return 'A' + n - 26;
}

int decode(char c){
  if(islower(c)) return c - 'a';
  return c - 'A' + 26;
}

int main(){
  while(const int n = getInt()){
    vector<int> v(n);
    REP(i,n) v[i] = getInt();

    char buff[256];
    scanf("%s", buff);

    for(char *s = buff; *s; s++){
      cout << encode((decode(*s) + 52 - v[(s - buff) % v.size()]) % 52);
    }
    cout << endl;
  }
  return 0;
}