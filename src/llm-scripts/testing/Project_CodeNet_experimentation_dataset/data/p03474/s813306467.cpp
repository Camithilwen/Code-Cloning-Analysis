#include <iostream>
#include <string>

using namespace std;

int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;

  for (int i = 0; i < S.size(); i++){
    if (i==A){
      if (S[i]!='-'){
        printf("No\n");
        return 0;
      }
    }else if (S[i]-'0' > 9 || S[i]-'0' < 0){
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}
