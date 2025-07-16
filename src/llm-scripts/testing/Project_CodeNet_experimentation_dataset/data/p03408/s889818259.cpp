#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){

  int N, M;
  cin >> N;
  vector<string> vec1(N);
  for (int i=0; i<N; i++){
    cin >> vec1.at(i);
  }
  cin >> M;
  vector<string> vec2(M);
  for (int i=0; i<M; i++){
    cin >> vec2.at(i);
  }

  int max=0;
  for (int i=0; i<N; i++){
    int sum=0;
    for (int j=0; j<N; j++){
      if (vec1.at(i)==vec1.at(j)){
        sum++;
      }
    }
    for (int k=0; k<M; k++){
      if (vec1.at(i)==vec2.at(k)){
        sum--;
      }
    }
    if (sum>max){
      swap(sum, max);
    }
  }

  cout << max << endl;
}
