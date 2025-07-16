#include <iostream>
using namespace std;
 
int main(){
    int A,B,C;
    cin >> A >> B >> C;
  
   if (A != B && A != C && B != C) {
     cout << "No" << endl;
   }
  else if (A == B && B == C) {
     cout << "No" << endl;
  }
  else if (A == B && A != C) {
    cout << "Yes" << endl;
  }
  else if (A == C && A != B) {
    cout << "Yes" << endl;
  }
  else if (C == B && A != C) {
    cout << "Yes" << endl;
  }
}
