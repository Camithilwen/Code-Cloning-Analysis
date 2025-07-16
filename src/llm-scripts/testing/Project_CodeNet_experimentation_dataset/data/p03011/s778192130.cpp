#include <iostream>
#include <vector>
using namespace std;

int main(){
  int A;
  int B;
  int C;
  cin >> A;
  cin >> B;
  cin>> C;
  vector <int> seged_vector;
  seged_vector.push_back(A+B);
  seged_vector.push_back(A+C);
  seged_vector.push_back(B+A);
  seged_vector.push_back(B+C);
  seged_vector.push_back(C+A);
  seged_vector.push_back(C+B);
  int seged=seged_vector[0];
  for(int i=1;i<seged_vector.size();i++){
    if(seged>seged_vector[i]){
      seged=seged_vector[i];
    }
  }
  cout << seged;
	return 0;
}
