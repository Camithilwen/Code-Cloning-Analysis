#include<iostream>
using namespace std;

int main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  cout << ((A<B ? A : B) + (C<D ? C : D)) << endl;
  return 0;
}
